/*
33. Search in Rotated Sorted Array
Medium

Problem: Rotated sorted array'de target değeri ara. O(log n) complexity gerekli.
Array ascending order'da sorted ama bilinmeyen bir pivot'ta rotate edilmiş.

Strateji: Modified Binary Search
1. Normal binary search'i modify et
2. Her iterasyonda hangi yarının sorted olduğunu belirle
3. Target'ın sorted yarıda olup olmadığını kontrol et
4. Uygun yarıya devam et

Zaman Karmaşıklığı: O(log n) - binary search
Alan Karmaşıklığı: O(1) - sadece pointer'lar kullanırız

Temel Optimizasyonlar:
1. Single binary search - no need to find pivot first
2. Smart half selection - determine sorted half
3. Range checking - target in sorted range?
4. Early termination - exact match found

Key Insight: Rotated array'de her zaman bir yarı tamamen sorted'dır
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Target bulundu
            if (nums[mid] == target) {
                return mid;
            }
            
            // Sol yarı sorted mı kontrol et
            if (nums[left] <= nums[mid]) {
                // Sol yarı sorted - target bu aralıkta mı?
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;  // Sol yarıda ara
                } else {
                    left = mid + 1;   // Sağ yarıda ara
                }
            }
            // Sağ yarı sorted
            else {
                // Sağ yarı sorted - target bu aralıkta mı?
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;   // Sağ yarıda ara
                } else {
                    right = mid - 1;  // Sol yarıda ara
                }
            }
        }
        
        return -1; // Target bulunamadı
    }
    
    // Alternative Solution: Find pivot first, then binary search
    int searchWithPivot(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        
        // Step 1: Pivot (minimum element) index'ini bul
        int pivot = findPivot(nums);
        
        // Step 2: Array rotate edilmemiş
        if (pivot == 0) {
            return binarySearch(nums, 0, n - 1, target);
        }
        
        // Step 3: Target hangi yarıda?
        if (nums[0] <= target) {
            // Sol yarıda ara (0 to pivot-1)
            return binarySearch(nums, 0, pivot - 1, target);
        } else {
            // Sağ yarıda ara (pivot to n-1)
            return binarySearch(nums, pivot, n - 1, target);
        }
    }
    
private:
    // Pivot (minimum element) index'ini bul
    int findPivot(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                left = mid + 1;  // Pivot sağ yarıda
            } else {
                right = mid;     // Pivot sol yarıda (mid dahil)
            }
        }
        
        return left;
    }
    
    // Standard binary search
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};