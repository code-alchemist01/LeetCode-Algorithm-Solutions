/*
20. Valid Parentheses
Easy

Problem: Sadece '(', ')', '{', '}', '[' ve ']' karakterlerini içeren bir string 
verildiğinde, bu string'in geçerli olup olmadığını belirle.

Geçerli string kuralları:
1. Açık parantezler aynı tip parantezlerle kapatılmalı
2. Açık parantezler doğru sırada kapatılmalı  
3. Her kapalı parantezin karşılık gelen açık parantezi olmalı

Strateji: Stack Veri Yapısı
- Açık parantezleri stack'e push et
- Kapalı parantez geldiğinde stack'ten pop et ve eşleştir
- Son durumda stack boş olmalı

Zaman Karmaşıklığı: O(n) - her karakter bir kez işlenir
Alan Karmaşıklığı: O(n) - worst case'de tüm karakterler stack'te

Temel Optimizasyonlar:
1. Erken sonlandırma - kapalı parantez fazlaysa
2. Hash map yerine switch-case - daha hızlı
3. Stack boyutu kontrolü - memory efficient
4. Single pass algoritması
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (char c : s) {
            // Açık parantezleri stack'e push et
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            // Kapalı parantezleri kontrol et
            else {
                // Stack boşsa, kapalı parantez fazla demektir
                if (st.empty()) return false;
                
                char top = st.top();
                st.pop();
                
                // Parantez eşleştirmesi kontrol et
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        
        // Stack boş olmalı - tüm parantezler eşleşmiş olmalı
        return st.empty();
    }
};