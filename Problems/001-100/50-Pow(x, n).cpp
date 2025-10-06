/*
50. Pow(x, n)
Zorluk: Orta

Problem Açıklaması:
pow(x, n) fonksiyonunu implement edin, x'in n'inci kuvvetini hesaplar (yani x^n).

Örnek 1:
Giriş: x = 2.00000, n = 10
Çıkış: 1024.00000

Örnek 2:
Giriş: x = 2.10000, n = 3
Çıkış: 9.26100

Örnek 3:
Giriş: x = 2.00000, n = -2
Çıkış: 0.25000
Açıklama: 2^-2 = 1/2^2 = 1/4 = 0.25

Kısıtlamalar:
-100.0 < x < 100.0
-2^31 <= n <= 2^31-1
n bir tamsayıdır.
Ya x sıfır değildir ya da n > 0.
-10^4 <= x^n <= 10^4

Strateji:
Fast Exponentiation (Binary Exponentiation) kullan:
1. n negatifse, x = 1/x ve n = -n yap
2. Her adımda n'yi yarıya böl, x'i karele
3. n tek ise result'ı x ile çarp

Zaman Karmaşıklığı: O(log n)
Alan Karmaşıklığı: O(1)
*/

#include <climits>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        
        double result = 1.0;
        double current_power = x;
        
        while (N > 0) {
            if (N & 1) {  // N is odd
                result *= current_power;
            }
            current_power *= current_power;
            N >>= 1;  // N = N / 2
        }
        
        return result;
    }
};
