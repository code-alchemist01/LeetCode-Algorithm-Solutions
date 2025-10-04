/*
39. Combination Sum
Zorluk: Orta

Problem Açıklaması:
Farklı tamsayılardan oluşan bir candidates dizisi ve bir target tamsayısı verildiğinde,
seçilen sayıların toplamı target'a eşit olan tüm benzersiz kombinasyonların listesini döndürün.
Kombinasyonları herhangi bir sırada döndürebilirsiniz.

Aynı sayı candidates'tan sınırsız sayıda seçilebilir. İki kombinasyon, seçilen sayılardan
en az birinin frekansı farklıysa benzersizdir.

Test durumları, verilen girdi için target'a toplanan benzersiz kombinasyon sayısının
150 kombinasyondan az olacağı şekilde oluşturulmuştur.

Örnek 1:
Giriş: candidates = [2,3,6,7], target = 7
Çıkış: [[2,2,3],[7]]
Açıklama:
2 ve 3 aday, ve 2 + 2 + 3 = 7. 2'nin birden fazla kez kullanılabileceğini unutmayın.
7 aday, ve 7 = 7.
Bunlar sadece iki kombinasyon.

Örnek 2:
Giriş: candidates = [2,3,5], target = 8
Çıkış: [[2,2,2,2],[2,3,3],[3,5]]

Örnek 3:
Giriş: candidates = [2], target = 1
Çıkış: []

Kısıtlamalar:
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
candidates'ın tüm elemanları farklıdır.
1 <= target <= 40

Strateji:
Backtracking (Geri İzleme) algoritması kullanarak tüm olası kombinasyonları keşfet.
Her adımda bir sayı seç ve hedef değerden çıkar, hedef 0 olduğunda geçerli kombinasyonu kaydet.

Zaman Karmaşıklığı: O(N^(T/M)) - N: candidates sayısı, T: target, M: minimum candidate
Alan Karmaşıklığı: O(T/M) - recursion depth
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// En Optimize Çözüm: Backtracking with Pruning
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        
        // Sıralama ile pruning optimizasyonu
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
        
        // Her candidate'ı dene
        for (int i = start; i < candidates.size(); i++) {
            // Pruning: eğer candidate target'tan büyükse, sonrakiler de büyük olacak
            if (candidates[i] > target) break;
            
            // Candidate'ı seç
            combination.push_back(candidates[i]);
            
            // Aynı candidate'ı tekrar kullanabilir (i'den başla, i+1'den değil)
            backtrack(candidates, target - candidates[i], i, combination, result);
            
            // Backtrack: candidate'ı geri al
            combination.pop_back();
        }
    }
};
