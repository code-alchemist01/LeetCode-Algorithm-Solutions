/*
3Sum Closest - Two Pointer Yaklaşımı

Bu problem, array'de target'a en yakın toplamı olan triplet'i bulma işlemidir.
3Sum'dan farkı: Exact match değil, closest match arıyoruz.

Algoritma Stratejisi:
1. Array'i sırala: Two pointer efficiency için
2. İlk element'i fix et: nums[i]
3. Kalan array'de two sum: closest to (target - nums[i])
4. Distance tracking: |current_sum - target| minimize et

Key Insight:
- Sorted array'de two pointer ile tüm kombinasyonları kontrol et
- Her adımda current sum ile target arasındaki distance'ı hesapla
- Minimum distance'ı track et ve corresponding sum'ı kaydet

Optimizasyon Teknikleri:
1. Early termination: Perfect match bulunca dur
2. Sorted array: Two pointer efficiency
3. Distance comparison: Absolute difference
4. Single pass: O(n²) complexity

Time: O(n²) - n iterations × n two-pointer
Space: O(1) - sadece variables (sorting hariç)
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int closest = nums[0] + nums[1] + nums[2];
        int minDiff = abs(closest - target);
        
        for (int i = 0; i < n - 2; ++i) {
            // Early termination if current element is too large
            if (i > 0 && nums[i] > target / 3 && minDiff <= target - nums[i] * 3) break;
            
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int l = i + 1, r = n - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                
                // Perfect match
                if (sum == target) return target;
                
                int diff = abs(sum - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    closest = sum;
                }
                
                // Optimized pointer movement
                if (sum < target) {
                    do { ++l; } while (l < r && nums[l] == nums[l-1]);
                } else {
                    do { --r; } while (l < r && nums[r] == nums[r+1]);
                }
            }
        }
        
        return closest;
    }
};