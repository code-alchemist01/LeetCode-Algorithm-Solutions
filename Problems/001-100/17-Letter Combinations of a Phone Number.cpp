/*
17. Letter Combinations of a Phone Number
Medium

Problem: 2-9 arası rakamlar içeren bir string verildiğinde, bu rakamların temsil 
edebileceği tüm olası harf kombinasyonlarını döndür.

Strateji: Backtracking ile DFS
- Telefon tuş takımı haritalama dizisi ile O(1) erişim
- Tüm kombinasyonları üretmek için özyinelemeli backtracking
- Boş girdi için erken sonlandırma
- Referans geçişi ile verimli string oluşturma

Zaman Karmaşıklığı: O(3^m × 4^n) - m: 3 harfli rakamlar, n: 4 harfli rakamlar
Alan Karmaşıklığı: O(3^m × 4^n) sonuç depolama + O(digits.length) özyineleme yığını

Temel Optimizasyonlar:
1. Telefon haritalama için static const dizi - cache dostu
2. String kopyalamayı önlemek için referans geçişi
3. Boş girdi için erken dönüş
4. push_back/pop_back ile verimli backtracking
5. Mümkün olduğunda result vektörü için alan ayırma
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Telefon tuş takımı haritalama - cache lokalitesi için optimize edilmiş
        static const string phone[] = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        string current;
        current.reserve(digits.length()); // Verimlilik için önceden alan ayır
        
        backtrack(digits, 0, current, result, phone);
        return result;
    }
    
private:
    void backtrack(const string& digits, int index, string& current, 
                   vector<string>& result, const string phone[]) {
        // Temel durum: rakamların sonuna ulaşıldı
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Mevcut rakam için harfleri al
        const string& letters = phone[digits[index] - '0'];
        
        // Mevcut rakam için her harfi dene
        for (char letter : letters) {
            current.push_back(letter);           // Seç
            backtrack(digits, index + 1, current, result, phone); // Keşfet
            current.pop_back();                  // Seçimi geri al (backtrack)
        }
    }
};