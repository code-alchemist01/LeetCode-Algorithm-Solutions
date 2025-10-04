/*
29. Divide Two Integers
Medium

Problem: İki integer dividend ve divisor verildiğinde, multiplication, division 
ve mod operator kullanmadan bölme işlemi yap. Integer division sıfıra doğru 
truncate edilmeli. 32-bit signed integer range içinde kalmalı.

Strateji: Bit Manipulation + Exponential Search
- Çarpma/bölme/mod kullanamayız
- Bit shifting ile exponential search
- Overflow kontrolü
- Sign handling

Zaman Karmaşıklığı: O(log n) - bit shifting sayesinde
Alan Karmaşıklığı: O(1) - sadece değişkenler kullanılır

Temel Optimizasyonlar:
1. Bit shifting - 2'nin katları ile hızlı çarpma
2. Exponential search - logaritmik time complexity
3. Overflow handling - 32-bit range kontrolü
4. Sign separation - pozitif sayılarla çalış
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case: -2^31 / -1 = 2^31 (overflow)
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        // Sign belirleme
        bool negative = (dividend < 0) ^ (divisor < 0);
        
        // Absolute value'ları al (overflow'dan kaçınmak için long kullan)
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);
        
        long long quotient = 0;
        
        // Exponential search ile bölme
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            long long multiple = 1;
            
            // En büyük katı bul (2^n * divisor <= dividend)
            while (absDividend >= (temp << 1)) {
                temp <<= 1;      // temp *= 2
                multiple <<= 1;  // multiple *= 2
            }
            
            // Bu katı çıkar
            absDividend -= temp;
            quotient += multiple;
        }
        
        // Sign uygula
        if (negative) {
            quotient = -quotient;
        }
        
        // 32-bit range kontrolü
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;
        
        return (int)quotient;
    }
};