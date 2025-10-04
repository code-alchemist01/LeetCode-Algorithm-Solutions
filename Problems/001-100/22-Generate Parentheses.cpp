/*
22. Generate Parentheses
Medium

Problem: n çift parantez verildiğinde, tüm geçerli parantez kombinasyonlarını 
oluşturan bir fonksiyon yaz.

Strateji: Backtracking with Constraints
- Her adımda '(' veya ')' ekleme seçeneği var
- Constraint'ler: open_count <= n, close_count <= open_count
- Base case: open_count == close_count == n
- Pruning: Invalid durumları erken tespit et

Zaman Karmaşıklığı: O(4^n / √n) - Catalan number
Alan Karmaşıklığı: O(4^n / √n) - result space + O(n) recursion stack

Temel Optimizasyonlar:
1. Early pruning - invalid durumları hemen kes
2. Pass by reference - string copying'i minimize et
3. Constraint checking - sadece valid seçenekleri dene
4. Backtracking template - clean recursive structure
*/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current = "";
        
        // Backtracking ile tüm geçerli kombinasyonları oluştur
        backtrack(result, current, 0, 0, n);
        
        return result;
    }
    
private:
    void backtrack(vector<string>& result, string& current, 
                   int open_count, int close_count, int n) {
        
        // Base case: n çift parantez tamamlandı
        if (open_count == n && close_count == n) {
            result.push_back(current);
            return;
        }
        
        // Choice 1: Açık parantez ekle (eğer limit aşılmamışsa)
        if (open_count < n) {
            current.push_back('(');
            backtrack(result, current, open_count + 1, close_count, n);
            current.pop_back(); // Backtrack
        }
        
        // Choice 2: Kapalı parantez ekle (eğer açık parantez varsa)
        if (close_count < open_count) {
            current.push_back(')');
            backtrack(result, current, open_count, close_count + 1, n);
            current.pop_back(); // Backtrack
        }
    }
};