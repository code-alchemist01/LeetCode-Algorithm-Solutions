"""
Arkadaşlar bu problemde integer'ı tersine çevirirken overflow kontrolü yapmamız gerekiyor.

Klasik yaklaşım string'e çevirip tersine çevirmek olabilir ama biz matematiksel yöntemi kullanacağız.
Her adımda sayının son basamağını alıp yeni sayıya ekliyoruz:
- result = result * 10 + (x % 10)
- x = x // 10

Kritik nokta: 32-bit integer sınırları [-2^31, 2^31-1] yani [-2147483648, 2147483647]
Overflow kontrolü için her adımda sınırları kontrol etmeliyiz.

Zaman karmaşıklığı: O(log x) - basamak sayısı kadar
Alan karmaşıklığı: O(1) - sabit alan kullanımı
"""

class Solution:
    def reverse(self, x):
        result = 0
        sign = 1 if x >= 0 else -1
        x = abs(x)
        
        while x:
            result = result * 10 + x % 10
            x //= 10
        
        result *= sign
        
        # Overflow check
        if result > 2147483647 or result < -2147483648:
            return 0
        
        return result