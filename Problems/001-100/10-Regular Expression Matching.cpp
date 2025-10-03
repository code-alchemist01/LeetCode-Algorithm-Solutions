/*
Regular Expression Matching - Dynamic Programming Yaklaşımı

Bu problem, regex pattern matching'in klasik implementasyonudur.
'.' herhangi bir karakteri, '*' önceki karakterin 0 veya daha fazlasını temsil eder.

Matematiksel Analiz:
- State: dp[i][j] = s[0..i-1] ile p[0..j-1] eşleşir mi?
- Base case: dp[0][0] = true (boş string boş pattern ile eşleşir)
- Transition: İki ana durum var
  1. Normal karakter veya '.' → dp[i][j] = dp[i-1][j-1] && match(s[i-1], p[j-1])
  2. '*' karakteri → İki seçenek:
     a) 0 match: dp[i][j] = dp[i][j-2]
     b) 1+ match: dp[i][j] = dp[i-1][j] && match(s[i-1], p[j-2])

Kritik Optimizasyon Stratejisi:
1. Bottom-up DP: Recursive overhead yok
2. 2D array: O(mn) space, clear state management
3. Pattern preprocessing: '*' durumlarını önceden handle et
4. Early termination: Impossible cases için

DP Recurrence Relation:
- p[j-1] != '*': dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
- p[j-1] == '*': dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'))

Time Complexity: O(m*n) - string ve pattern uzunlukları
Space Complexity: O(m*n) - DP tablosu
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        
        // dp[i][j]: s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c* (can match empty string)
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        
        // Fill DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // '*' case: zero match OR one+ match
                    dp[i][j] = dp[i][j - 2] || 
                              (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    // Normal character or '.'
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        
        return dp[m][n];
    }
};