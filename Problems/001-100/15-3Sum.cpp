/*
3Sum - Two Pointer Yaklaşımı

Bu problem, array'de toplamı 0 olan unique triplet'leri bulma işlemidir.
Temel zorluk: Duplicate triplet'lerden kaçınmak ve O(n²) complexity'de çözmek.

Algoritma Seçenekleri:
1. Brute Force: O(n³) - her triplet'i kontrol et
2. Hash Set: O(n²) space - two sum mantığı
3. Two Pointer: O(n²) time, O(1) space ✓

Two Pointer Stratejisi:
1. Array'i sırala: Duplicate handling için
2. İlk element'i fix et: nums[i]
3. Kalan array'de two sum: target = -nums[i]
4. Duplicate skip: Aynı değerleri atla

Duplicate Handling:
- İlk element duplicate: i'yi skip et
- İkinci element duplicate: left'i skip et  
- Üçüncü element duplicate: right'ı skip et

Optimizasyon Teknikleri:
1. Early termination: nums[i] > 0 ise dur
2. Sorted array: Two pointer efficiency
3. Skip duplicates: Unique triplet guarantee
4. In-place: O(1) extra space

Time: O(n²) - n iterations × n two-pointer
Space: O(1) - sadece pointers (sorting hariç)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Array'i sırala - duplicate handling için
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // Early termination: pozitif sayılar
            if (nums[i] > 0) break;
            
            // İlk element duplicate skip
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            // Two pointer setup
            int left = i + 1;
            int right = n - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    // Triplet bulundu
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Left duplicate skip
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    
                    // Right duplicate skip
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }
                    
                    // Move both pointers
                    ++left;
                    --right;
                    
                } else if (sum < target) {
                    ++left;  // Daha büyük sum gerekli
                } else {
                    --right; // Daha küçük sum gerekli
                }
            }
        }
        
        return result;
    }
};