/*
Palindrome Number - Matematiksel Yaklaşım ve Optimizasyon

Bu problem, bir integer'ın palindrom olup olmadığını kontrol etme işlemidir.
Palindrom: Soldan sağa ve sağdan sola aynı okunan sayılar (121, 1331, vb.)

Matematiksel Analiz:
- Negatif sayılar: Asla palindrom değil (işaret sebebiyle)
- Tek haneli: Her zaman palindrom (0-9)
- Son hanesi 0: Sadece 0 palindrom (10, 20, 100 değil)
- Yarı çevirme: Sadece yarısını çevir, karşılaştır

Kritik Optimizasyon Stratejisi:
1. Early returns: Negatif ve son hanesi 0 olanlar
2. Half reversal: Tüm sayıyı çevirmek yerine yarısını çevir
3. Overflow yok: Sadece yarı çevirdiğimiz için overflow riski yok
4. Mathematical approach: String conversion yok

Half Reversal Mantığı:
- x = 1221 → reversed = 12, x = 12 → Eşit!
- x = 12321 → reversed = 123, x = 1 → reversed/10 == x (tek haneli orta)

Time Complexity: O(log n) - digit sayısının yarısı kadar
Space Complexity: O(1) - sabit extra space
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // Negatif sayılar palindrom değil
        // Son hanesi 0 olan sayılar (0 hariç) palindrom değil
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int reversed = 0;
        
        // Yarı çevirme: x'in yarısını çevir
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        // Çift haneli: x == reversed
        // Tek haneli: x == reversed / 10 (ortadaki digit'i atla)
        return x == reversed || x == reversed / 10;
    }
};