/*
Longest Common Prefix - Vertical Scanning Yaklaşımı

Bu problem, string array'inde en uzun ortak prefix'i bulma işlemidir.
Temel strateji: İlk string'i referans alıp, diğerleriyle karakter karakter karşılaştır.

Algoritma Seçenekleri:
1. Horizontal Scanning: Her string'i sırayla karşılaştır
2. Vertical Scanning: Her pozisyonu tüm string'lerde kontrol et ✓
3. Divide & Conquer: Recursive yaklaşım
4. Binary Search: Prefix uzunluğu üzerinde binary search

Vertical Scanning Avantajları:
- Early termination: İlk farklılıkta dur
- Cache friendly: Aynı pozisyonu art arda oku
- Simple logic: Tek loop, minimal complexity
- Optimal for short prefixes: Çoğu durumda en hızlı

Optimizasyon Teknikleri:
1. Empty check: Boş array kontrolü
2. First string reference: İlk string'i base al
3. Character-by-character: Pozisyon bazlı karşılaştırma
4. Early exit: İlk farklılıkta return

Time: O(S) - S = tüm karakterlerin toplamı
Space: O(1) - sadece index değişkenleri
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // İlk string'i referans al
        const string& first = strs[0];
        
        // Her karakter pozisyonu için
        for (int i = 0; i < first.length(); ++i) {
            char c = first[i];
            
            // Diğer tüm string'leri kontrol et
            for (int j = 1; j < strs.size(); ++j) {
                // String sonu veya farklı karakter
                if (i >= strs[j].length() || strs[j][i] != c) {
                    return first.substr(0, i);
                }
            }
        }
        
        // Tüm ilk string ortak prefix
        return first;
    }
};