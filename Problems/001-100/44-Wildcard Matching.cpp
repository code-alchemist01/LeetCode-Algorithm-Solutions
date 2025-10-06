/*
44. Wildcard Matching
Zorluk: Zor

Problem Açıklaması:
Bir giriş string'i (s) ve pattern (p) verildiğinde, '?' ve '*' destekli 
wildcard pattern matching implementasyonu yapın:

'?' herhangi bir tek karakterle eşleşir.
'*' herhangi bir karakter dizisiyle eşleşir (boş dizi dahil).
Eşleşme tüm giriş string'ini kapsamalıdır (kısmi değil).

Örnek 1:
Giriş: s = "aa", p = "a"
Çıkış: false
Açıklama: "a" tüm "aa" string'i ile eşleşmez.

Örnek 2:
Giriş: s = "aa", p = "*"
Çıkış: true
Açıklama: '*' herhangi bir dizi ile eşleşir.

Örnek 3:
Giriş: s = "cb", p = "?a"
Çıkış: false
Açıklama: '?' 'c' ile eşleşir, ama ikinci harf 'a', 'b' ile eşleşmez.

Kısıtlamalar:
0 <= s.length, p.length <= 2000
s sadece küçük İngilizce harfler içerir.
p sadece küçük İngilizce harfler, '?' veya '*' içerir.

Strateji:
Dynamic Programming ile optimal çözüm.
dp[i][j] = s[0..i-1] ve p[0..j-1] eşleşir mi?

Zaman Karmaşıklığı: O(m × n)
Alan Karmaşıklığı: O(m × n)
*/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> prev(n + 1, false), curr(n + 1, false);
        
        prev[0] = true;
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') prev[j] = prev[j-1];
        }
        
        for (int i = 1; i <= m; i++) {
            curr[0] = false;
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    curr[j] = curr[j-1] || prev[j];
                } else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                    curr[j] = prev[j-1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        
        return prev[n];
    }
};
