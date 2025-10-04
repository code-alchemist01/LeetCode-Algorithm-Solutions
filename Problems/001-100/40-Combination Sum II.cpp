/*
40. Combination Sum II
Zorluk: Orta

Problem Açıklaması:
Bir candidates sayı koleksiyonu ve bir target sayısı verildiğinde,
candidates'taki sayıların toplamı target'a eşit olan tüm benzersiz kombinasyonları bulun.

candidates'taki her sayı kombinasyonda sadece bir kez kullanılabilir.

Not: Çözüm seti tekrarlanan kombinasyonlar içermemelidir.

Örnek 1:
Giriş: candidates = [10,1,2,7,6,1,5], target = 8
Çıkış: [[1,1,6],[1,2,5],[1,7],[2,6]]

Örnek 2:
Giriş: candidates = [2,5,2,1,2], target = 5
Çıkış: [[1,2,2],[5]]

Kısıtlamalar:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

Strateji:
1. Diziyi sırala (duplicate'ları yan yana getirmek için)
2. Backtracking kullan ama her sayıyı sadece bir kez kullan
3. Duplicate kombinasyonları önlemek için aynı seviyede aynı sayıyı atla

Zaman Karmaşıklığı: O(2^N) - her eleman için dahil et/etme kararı
Alan Karmaşıklığı: O(target) - recursion depth
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        
        // Sıralama: duplicate'ları yan yana getir
        sort(candidates.begin(), candidates.end());
        
        backtrack(candidates, target, 0, combination, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& candidates, int target, int start, 
                   vector<int>& combination, vector<vector<int>>& result) {
        // Temel durum: hedef 0'a ulaştı
        if (target == 0) {
            result.push_back(combination);
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            // Pruning: eğer candidate target'tan büyükse dur
            if (candidates[i] > target) break;
            
            // Duplicate'ları atla: aynı seviyede aynı sayıyı kullanma
            // i > start: sadece aynı recursion seviyesinde atla
            if (i > start && candidates[i] == candidates[i-1]) continue;
            
            // Candidate'ı seç
            combination.push_back(candidates[i]);
            
            // Her sayı sadece bir kez kullanılabilir (i+1'den başla)
            backtrack(candidates, target - candidates[i], i + 1, combination, result);
            
            // Backtrack: candidate'ı geri al
            combination.pop_back();
        }
    }
};

