/*
Integer to Roman - Greedy Mapping Yaklaşımı

Bu problem, decimal sayıyı Roman rakamlarına çevirme işlemidir.
Temel mantık: En büyük değerden başlayarak greedy olarak çıkar.

Roman Numeral Kuralları:
- Normal semboller: I=1, V=5, X=10, L=50, C=100, D=500, M=1000
- Subtractive forms: IV=4, IX=9, XL=40, XC=90, CD=400, CM=900
- Maksimum 3 kez tekrar: III, XXX, CCC, MMM
- 4 ve 9 için subtractive form kullan

Greedy Stratejisi:
En büyük değerden başla, mümkün olduğunca çıkar.
Örnek: 3749 = MMM(3000) + DCC(700) + XL(40) + IX(9)

Optimizasyon Teknikleri:
1. Hardcoded mapping: Tüm değer-sembol çiftleri önceden tanımlı
2. Descending order: Büyükten küçüğe sıralı array
3. Greedy selection: Her adımda maksimum değeri seç
4. String concatenation: Efficient string building

Time: O(1) - maksimum 13 farklı sembol var
Space: O(1) - sabit boyutlu arrays
*/

class Solution {
public:
    string intToRoman(int num) {
        static const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result;
        result.reserve(15); // Pre-allocate memory
        
        for (int i = 0; i < 13; ++i) {
            int count = num / values[i];
            if (count) {
                for (int j = 0; j < count; ++j) {
                    result += symbols[i];
                }
                num %= values[i];
            }
        }
        
        return result;
    }
};