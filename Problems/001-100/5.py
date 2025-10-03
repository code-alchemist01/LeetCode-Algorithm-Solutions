class Solution:
    def longestPalindrome(self, s):
        n = len(s)
        # Kısa stringler için direkt döndürür
        if n < 2:
            return s
        
        start = 0  # En uzun palindromun başlangıç indeksi
        max_len = 1  # Şu ana kadar bulunan en uzun palindrom uzunluğunu verir
        
        for i in range(n):
            # Her karakteri merkez kabul ederek palindrom arar
            l = r = i
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            # Bulunan palindrom daha uzunsa günceller
            if r - l - 1 > max_len:
                start = l + 1
                max_len = r - l - 1
            
            # İki karakter arası merkez kabul ederek palindrom arar
            l, r = i, i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                l -= 1
                r += 1
            # Bulunan palindrom daha uzunsa günceller
            if r - l - 1 > max_len:
                start = l + 1
                max_len = r - l - 1
        
        return s[start:start + max_len]