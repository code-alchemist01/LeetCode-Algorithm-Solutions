/*
28. Find the Index of the First Occurrence in a String
Easy

Problem: İki string needle ve haystack verildiğinde, needle'ın haystack içindeki 
ilk occurrence'ının index'ini return et. Eğer needle haystack'in parçası değilse -1 return et.

Strateji: Sliding Window / Brute Force
- Haystack'i traverse et
- Her pozisyonda needle ile match olup olmadığını kontrol et
- İlk match'i bulunca index'ini return et

Zaman Karmaşıklığı: O(n*m) - n: haystack length, m: needle length
Alan Karmaşıklığı: O(1) - sadece index'ler kullanılır

Temel Optimizasyonlar:
1. Early termination - needle uzunluğu kontrolü
2. Built-in function alternative - substr kullanımı
3. Edge case handling - boş string kontrolü
4. Single loop approach - basit ve anlaşılır

Not: KMP algoritması O(n+m) time complexity sağlar ama implementation karmaşık.
Bu problem için basit approach yeterli.
*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        // Edge case: needle boş ise 0 return et
        if (needle.empty()) return 0;
        
        // Needle haystack'ten uzunsa -1 return et
        if (needle.length() > haystack.length()) return -1;
        
        // Haystack'i traverse et
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            // Current pozisyondan needle uzunluğu kadar substring al
            if (haystack.substr(i, needle.length()) == needle) {
                return i; // İlk match bulundu
            }
        }
        
        return -1; // Match bulunamadı
    }
    
    // Alternative implementation - manual character comparison
    int strStr_Manual(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (needle.length() > haystack.length()) return -1;
        
        for (int i = 0; i <= haystack.length() - needle.length(); i++) {
            int j = 0;
            // Character by character comparison
            while (j < needle.length() && haystack[i + j] == needle[j]) {
                j++;
            }
            // Tüm karakterler match etti
            if (j == needle.length()) {
                return i;
            }
        }
        
        return -1;
    }
};