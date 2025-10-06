/*
46. Permutations
Zorluk: Orta

Problem Açıklaması:
Farklı tamsayılardan oluşan nums array'i verildiğinde, 
tüm olası permütasyonları döndürün. Cevabı herhangi bir sırada döndürebilirsiniz.

Örnek 1:
Giriş: nums = [1,2,3]
Çıkış: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Örnek 2:
Giriş: nums = [0,1]
Çıkış: [[0,1],[1,0]]

Örnek 3:
Giriş: nums = [1]
Çıkış: [[1]]

Kısıtlamalar:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums'ın tüm tamsayıları benzersizdir.

Strateji:
Backtracking ile tüm permütasyonları generate et.
Her pozisyon için kullanılmamış elemanları dene.

Zaman Karmaşıklığı: O(n! × n)
Alan Karmaşıklığı: O(n)
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
    
private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]);
        }
    }
};