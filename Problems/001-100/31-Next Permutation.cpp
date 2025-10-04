/*
31. Next Permutation
Medium

Problem: Bir integer array'in next lexicographically greater permutation'ını bul.
Eğer böyle bir arrangement mümkün değilse, array'i ascending order'da arrange et.
In-place ve constant extra memory kullanmalı.

Strateji: Lexicographic Order Algorithm
1. Sağdan sola traverse et, decreasing sequence'i bul
2. Pivot point'i belirle (ilk artan element)
3. Pivot'tan büyük en küçük element'i bul
4. Swap yap ve suffix'i reverse et

Zaman Karmaşıklığı: O(n) - array'i birkaç kez traverse ederiz
Alan Karmaşıklığı: O(1) - sadece pointer'lar kullanırız

Temel Optimizasyonlar:
1. Single pass algorithm - efficient traversal
2. In-place operations - no extra space
3. Reverse instead of sort - O(n) vs O(n log n)
4. Early termination - optimal pivot finding
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        
        // Step 1: Sağdan sola traverse et, pivot point'i bul
        // Pivot: sağdan ilk artan element (nums[i] < nums[i+1])
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        // Step 2: Eğer pivot bulunamadıysa, array descending order'da
        // En küçük permutation'a (ascending) çevir
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        // Step 3: Pivot'tan büyük en küçük element'i bul (sağdan)
        int successor = -1;
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                successor = i;
                break;
            }
        }
        
        // Step 4: Pivot ile successor'ı swap et
        swap(nums[pivot], nums[successor]);
        
        // Step 5: Pivot'tan sonraki kısmı reverse et
        // Bu kısım descending order'da, ascending'e çevir
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};