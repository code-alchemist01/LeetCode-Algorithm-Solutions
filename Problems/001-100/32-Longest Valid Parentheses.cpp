/*
32. Longest Valid Parentheses
Hard

Problem: Sadece '(' ve ')' karakterlerini içeren bir string'de en uzun valid parentheses substring'in uzunluğunu bul.

Strateji: Dynamic Programming
1. dp[i] = i pozisyonunda biten en uzun valid parentheses uzunluğu
2. ')' karakteri için kontrol et:
   - Önceki karakter '(' ise: dp[i] = dp[i-2] + 2
   - Önceki karakter ')' ise ve matching '(' varsa: dp[i] = dp[i-1] + 2 + dp[match_index-1]
3. Maximum değeri track et

Zaman Karmaşıklığı: O(n) - string'i bir kez traverse ederiz
Alan Karmaşıklığı: O(n) - dp array için

Temel Optimizasyonlar:
1. Single pass DP - linear time
2. State transition optimization
3. Boundary checking for safety
4. Maximum tracking during iteration

Alternative Approaches:
- Stack-based: O(n) time, O(n) space
- Two-pass counting: O(n) time, O(1) space
- DP approach: Most intuitive and clear
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        
        // dp[i] = i pozisyonunda biten en uzun valid parentheses uzunluğu
        vector<int> dp(n, 0);
        int maxLen = 0;
        
        // i=1'den başla çünkü tek karakter valid olamaz
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                // Case 1: s[i-1] == '(' -> "()" pattern
                if (s[i-1] == '(') {
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                }
                // Case 2: s[i-1] == ')' ve dp[i-1] > 0 -> "))" pattern
                else if (dp[i-1] > 0) {
                    // Matching '(' pozisyonunu bul
                    int matchIndex = i - dp[i-1] - 1;
                    
                    // Matching '(' var mı kontrol et
                    if (matchIndex >= 0 && s[matchIndex] == '(') {
                        dp[i] = dp[i-1] + 2 + (matchIndex > 0 ? dp[matchIndex-1] : 0);
                    }
                }
                
                // Maximum uzunluğu güncelle
                maxLen = max(maxLen, dp[i]);
            }
            // s[i] == '(' için dp[i] = 0 (default)
        }
        
        return maxLen;
    }
    
    // Alternative Solution: Stack-based approach
    int longestValidParenthesesStack(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        
        stack<int> stk;
        stk.push(-1); // Base index
        int maxLen = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                
                if (stk.empty()) {
                    stk.push(i); // New base
                } else {
                    maxLen = max(maxLen, i - stk.top());
                }
            }
        }
        
        return maxLen;
    }
    
    // Alternative Solution: Two-pass O(1) space
    int longestValidParenthesesTwoPass(string s) {
        int n = s.length();
        if (n <= 1) return 0;
        
        int maxLen = 0;
        
        // Left to right pass
        int left = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        
        // Right to left pass
        left = right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            
            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        
        return maxLen;
    }
};