/*
38. Count and Say
Zorluk: Orta

Problem Açıklaması:
Count-and-say dizisi, özyinelemeli formülle tanımlanan bir rakam dizisi dizisidir:

countAndSay(1) = "1"
countAndSay(n), countAndSay(n - 1)'in run-length encoding'idir.

Run-length encoding (RLE), ardışık özdeş karakterleri (2 veya daha fazla kez tekrarlanan)
karakterin ve karakterlerin sayısını işaretleyen sayının birleşimi ile değiştirerek çalışan
bir dize sıkıştırma yöntemidir.

Örneğin, "3322251" dizesini sıkıştırmak için:
- "33" → "23" (iki tane 3)
- "222" → "32" (üç tane 2)  
- "5" → "15" (bir tane 5)
- "1" → "11" (bir tane 1)
Böylece sıkıştırılmış dize "23321511" olur.

Pozitif bir n tamsayısı verildiğinde, count-and-say dizisinin n'inci elemanını döndürün.

Örnek 1:
Giriş: n = 4
Çıkış: "1211"
Açıklama:
countAndSay(1) = "1"
countAndSay(2) = "1"'in RLE'si = "11"
countAndSay(3) = "11"'in RLE'si = "21"  
countAndSay(4) = "21"'in RLE'si = "1211"

Örnek 2:
Giriş: n = 1
Çıkış: "1"
Açıklama: Bu temel durumdur.

Kısıtlamalar:
1 <= n <= 30

Strateji:
1. Temel durum: n = 1 için "1" döndür
2. Her adımda önceki dizgeyi oku ve run-length encoding uygula
3. Ardışık aynı karakterleri say ve "sayı + karakter" formatında birleştir

Zaman Karmaşıklığı: O(n * m) - n iterasyon, her iterasyonda m uzunluğunda dize işleme
Alan Karmaşıklığı: O(m) - her adımda yeni dize oluşturma
*/

#include <iostream>
#include <string>

using namespace std;

// En Optimize Çözüm: String Builder Yaklaşımı
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string current = "1";
        
        for (int i = 2; i <= n; i++) {
            current = buildNextSequence(current);
        }
        
        return current;
    }
    
private:
    // Verimli string oluşturma ile run-length encoding
    string buildNextSequence(const string& s) {
        string result;
        result.reserve(s.length() * 2); // Bellek optimizasyonu
        
        int i = 0;
        while (i < s.length()) {
            char digit = s[i];
            int count = 1;
            
            // Aynı rakamları say
            while (i + count < s.length() && s[i + count] == digit) {
                count++;
            }
            
            // Sayı ve rakamı ekle
            result += to_string(count) + digit;
            i += count;
        }
        
        return result;
    }
};

int main() {
    cout << "=== 38. Count and Say Çözümü ===" << endl;
    
    Solution sol;
    
    // Test Case 1: Örnek 1
    cout << "\nTest Case 1:" << endl;
    cout << "countAndSay(4) = \"" << sol.countAndSay(4) << "\"" << endl;
    
    // Test Case 2: Örnek 2  
    cout << "\nTest Case 2:" << endl;
    cout << "countAndSay(1) = \"" << sol.countAndSay(1) << "\"" << endl;
    
    // Dizinin gelişimini göster
    cout << "\n=== Count and Say Dizisi Gösterimi ===" << endl;
    for (int i = 1; i <= 8; i++) {
        string result = sol.countAndSay(i);
        cout << "n = " << i << ": \"" << result << "\"" << endl;
    }
    
    return 0;
}