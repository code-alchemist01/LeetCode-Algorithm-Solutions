/*
47. Permutations II
Zorluk: Orta

Problem Açıklaması:
Duplicate içerebilen nums koleksiyonu verildiğinde, 
tüm olası benzersiz permütasyonları herhangi bir sırada döndürün.

Örnek 1:
Giriş: nums = [1,1,2]
Çıkış: [[1,1,2],[1,2,1],[2,1,1]]

Örnek 2:
Giriş: nums = [1,2,3]
Çıkış: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Kısıtlamalar:
1 <= nums.length <= 8
-10 <= nums[i] <= 10

Strateji:
1. Array'i sort et (duplicate'ları yanyana getir)
2. Backtracking ile permutation generate et
3. Duplicate'ları skip et (aynı level'da aynı değeri tekrar kullanma)

Zaman Karmaşıklığı: O(n! × n)
Alan Karmaşıklığı: O(n)
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> current;
        
        sort(nums.begin(), nums.end());
        backtrack(nums, current, used, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, vector<int>& current, 
                   vector<bool>& used, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            
            // Skip duplicates: if current element equals previous and previous is not used
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            
            current.push_back(nums[i]);
            used[i] = true;
            
            backtrack(nums, current, used, result);
            
            current.pop_back();
            used[i] = false;
        }
    }
};
