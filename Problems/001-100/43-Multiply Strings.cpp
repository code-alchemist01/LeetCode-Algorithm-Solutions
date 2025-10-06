/*
43. Multiply Strings
Zorluk: Orta

Problem Açıklaması:
String olarak temsil edilen iki negatif olmayan tamsayı num1 ve num2 verildiğinde,
num1 ve num2'nin çarpımını, yine string olarak temsil edilen şekilde döndürün.

Not: Herhangi bir built-in BigInteger kütüphanesi kullanmamalı veya 
girişleri doğrudan tamsayıya çevirmemelisiniz.

Örnek 1:
Giriş: num1 = "2", num2 = "3"
Çıkış: "6"

Örnek 2:
Giriş: num1 = "123", num2 = "456"
Çıkış: "56088"

Kısıtlamalar:
1 <= num1.length, num2.length <= 200
num1 ve num2 sadece rakamlardan oluşur.
num1 ve num2, 0 sayısının kendisi hariç, başında sıfır içermez.

Strateji:
Geleneksel çarpma algoritmasını simüle et. Her basamağı çarp ve elde değerini yönet.
Sonuç dizisinin boyutu en fazla m + n olabilir (m ve n giriş uzunlukları).

Zaman Karmaşıklığı: O(m × n) - her basamak çifti için işlem
Alan Karmaşıklığı: O(m + n) - sonuç dizisi için
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size(), n = num2.size();
        string result(m + n, '0');
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + (result[p2] - '0');
                
                result[p2] = (sum % 10) + '0';
                result[p1] += sum / 10;
            }
        }
        
        size_t start = result.find_first_not_of('0');
        return start == string::npos ? "0" : result.substr(start);
    }
};

