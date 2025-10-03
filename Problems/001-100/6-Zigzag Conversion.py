"""
Arkadaşlar bu problemde zigzag pattern'ı simüle etmek yerine matematiksel bir yaklaşım kullanacağız.

Zigzag deseninde her satır için karakterlerin indeksleri belirli bir pattern takip eder:
- İlk satır: 0, 2*(numRows-1), 4*(numRows-1), ...
- Son satır: numRows-1, numRows-1+2*(numRows-1), ...
- Orta satırlar: i, 2*(numRows-1)-i, i+2*(numRows-1), 2*2*(numRows-1)-i, ...

Bu pattern'ı kullanarak her satırdaki karakterleri doğrudan hesaplayabiliriz.
Zaman karmaşıklığı: O(n), Alan karmaşıklığı: O(1) (sonuç hariç)
"""

class Solution:
    def convert(self, s, numRows):
        # Edge case: tek satır veya string kısa ise direkt döndür
        if numRows == 1 or numRows >= len(s):
            return s
        
        result = []
        n = len(s)
        cycle_len = 2 * numRows - 2  # Bir zigzag döngüsünün uzunluğu
        
        # Her satırı ayrı ayrı işle
        for i in range(numRows):
            j = i  # İlk karakter indeksi
            
            while j < n:
                result.append(s[j])  # Ana karakter
                
                # Orta satırlar için ara karakteri de ekle
                if i != 0 and i != numRows - 1:
                    next_j = j + cycle_len - 2 * i
                    if next_j < n:
                        result.append(s[next_j])
                
                j += cycle_len  # Bir sonraki döngüye geç
        
        return ''.join(result)