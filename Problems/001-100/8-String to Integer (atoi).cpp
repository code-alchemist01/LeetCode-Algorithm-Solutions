/*
String to Integer (atoi) - Matematiksel Yaklaşım ve Optimizasyon

Bu problem, bir string'i 32-bit signed integer'a dönüştürme işlemidir.
Klasik atoi fonksiyonunun implementasyonudur ancak overflow kontrolü gerektirir.

Matematiksel Analiz:
- Whitespace: Leading boşlukları atla
- Sign Detection: İlk karakter '+' veya '-' ise işareti belirle
- Digit Processing: Her digit için result = result * 10 + digit
- Overflow Control: 32-bit sınırları [-2^31, 2^31-1] = [-2147483648, 2147483647]

Kritik Optimizasyon Noktaları:
1. Early termination: İlk non-digit karakterde dur
2. Proactive overflow check: result > INT_MAX/10 kontrolü
3. Edge case handling: Leading zeros, empty string, sadece işaret
4. Single pass: O(n) time, O(1) space

Overflow Detection Stratejisi:
- result > 214748364 ise kesinlikle overflow
- result == 214748364 ve digit > 7 ise positive overflow
- result == 214748364 ve digit > 8 ise negative overflow

Time Complexity: O(n) - string uzunluğu kadar
Space Complexity: O(1) - sabit extra space
*/

#include <climits>

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        
        // Skip whitespace
        while (i < n && s[i] == ' ') i++;
        
        // Check sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        
        long result = 0;
        
        // Process digits
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            result = result * 10 + (s[i] - '0');
            
            // Overflow check
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && result > (long)INT_MAX + 1) return INT_MIN;
            
            i++;
        }
        
        return (int)(result * sign);
    }
};