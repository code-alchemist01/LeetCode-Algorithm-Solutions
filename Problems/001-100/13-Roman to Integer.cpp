/*
Roman to Integer - Single Pass Yaklaşımı

Bu problem, Roman rakamlarını decimal sayıya çevirme işlemidir.
Temel kural: Soldan sağa okurken, küçük değer büyük değerden önce gelirse çıkar.

Roman Numeral Mantığı:
- Normal durum: VI = V + I = 5 + 1 = 6
- Subtractive durum: IV = V - I = 5 - 1 = 4
- Anahtar: Bir sonraki karaktere bakarak karar ver

Algoritma Stratejisi:
Soldan sağa tek geçişte, her karakter için:
1. Mevcut karakterin değerini al
2. Bir sonraki karakter daha büyükse: çıkar (subtractive)
3. Değilse: topla (normal)

Optimizasyon Teknikleri:
1. Single pass: O(n) time, tek geçiş
2. Lookup table: Karakter-değer mapping
3. Peek ahead: Bir sonraki karaktere bak
4. Early decision: Her adımda topla/çıkar kararı

Time: O(n) - string uzunluğu kadar
Space: O(1) - sabit boyutlu lookup table
*/

class Solution {
public:
    int romanToInt(string s) {
        static const int values[128] = {
            ['I'] = 1, ['V'] = 5, ['X'] = 10, ['L'] = 50,
            ['C'] = 100, ['D'] = 500, ['M'] = 1000
        };
        
        int result = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            int current = values[s[i]];
            
            // Peek ahead: bir sonraki karakter daha büyükse çıkar
            if (i + 1 < n && current < values[s[i + 1]]) {
                result -= current;
            } else {
                result += current;
            }
        }
        
        return result;
    }
};