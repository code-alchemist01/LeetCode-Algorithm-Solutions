/*
35. Search Insert Position
Easy

Problem: Sorted array'de target'ı ara. Bulursa index'ini, bulamazsa insert edilecek pozisyonu return et.
O(log n) complexity gerekli.

Strateji: Modified Binary Search
1. Standard binary search uygula
2. Target bulunursa index'ini return et
3. Target bulunamazsa left pointer insert pozisyonunu gösterir
4. Loop bittiğinde left = insert position

Zaman Karmaşıklığı: O(log n) - binary search
Alan Karmaşıklığı: O(1) - sadece pointer'lar kullanırız

Temel Optimizasyonlar:
1. Single binary search - no extra logic needed
2. Natural insert position - left pointer gives answer
3. No special cases - works for all scenarios
4. Clean and simple implementation

Key Insight: Binary search'in doğal özelliği - loop bittiğinde left = insert position
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;  // Target bulundu
            } else if (nums[mid] < target) {
                left = mid + 1;  // Sağ yarıda ara
            } else {
                right = mid - 1; // Sol yarıda ara
            }
        }
        
        // Target bulunamadı - left insert pozisyonunu gösterir
        return left;
    }
    
    // Alternative Solution: Explicit insert position logic
    int searchInsertExplicit(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Edge cases
        if (target <= nums[0]) return 0;
        if (target > nums[n-1]) return n;
        
        int left = 0, right = n - 1;
        
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
        
        return left;
    }
    
    // Alternative Solution: Lower bound approach
    int searchInsertLowerBound(vector<int>& nums, int target) {
        // lower_bound returns iterator to first element >= target
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
    }
    
    // Alternative Solution: Recursive approach
    int searchInsertRecursive(vector<int>& nums, int target) {
        return binarySearchRecursive(nums, target, 0, nums.size() - 1);
    }
    
private:
    int binarySearchRecursive(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return left;  // Insert position
        }
        
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearchRecursive(nums, target, mid + 1, right);
        } else {
            return binarySearchRecursive(nums, target, left, mid - 1);
        }
    }
};