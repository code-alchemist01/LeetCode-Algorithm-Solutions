/*
49. Group Anagrams
Zorluk: Orta

Problem Açıklaması:
String array'i strs verildiğinde, anagramları gruplandırın. 
Cevabı herhangi bir sırada döndürebilirsiniz.

Örnek 1:
Giriş: strs = ["eat","tea","tan","ate","nat","bat"]
Çıkış: [["bat"],["nat","tan"],["ate","eat","tea"]]

Açıklama:
"bat" string'ini yeniden düzenleyerek başka bir string oluşturulamaz.
"nat" ve "tan" string'leri anagramdır çünkü birbirlerini oluşturacak şekilde yeniden düzenlenebilir.
"ate", "eat", ve "tea" string'leri anagramdır çünkü birbirlerini oluşturacak şekilde yeniden düzenlenebilir.

Örnek 2:
Giriş: strs = [""]
Çıkış: [[""]]

Örnek 3:
Giriş: strs = ["a"]
Çıkış: [["a"]]

Kısıtlamalar:
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] küçük İngilizce harflerden oluşur.

Strateji:
1. Her string'i sort et (anagram key olarak kullan)
2. HashMap ile aynı key'e sahip string'leri grupla
3. HashMap'teki tüm grupları result'a ekle

Zaman Karmaşıklığı: O(n * k * log k) - n: string sayısı, k: ortalama string uzunluğu
Alan Karmaşıklığı: O(n * k)
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        
        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            groups[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto& pair : groups) {
            result.push_back(move(pair.second));
        }
        
        return result;
    }
};
