/*
34. Find First and Last Position of Element in Sorted Array
Medium

Problem: Sorted array'de target'ın ilk ve son pozisyonunu bul.
Target yoksa [-1, -1] return et. O(log n) complexity gerekli.

Strateji: Two Binary Searches
1. İlk pozisyon için binary search (leftmost)
2. Son pozisyon için binary search (rightmost)
3. Her ikisi de O(log n) - toplam O(log n)

Zaman Karmaşıklığı: O(log n) - iki binary search
Alan Karmaşıklığı: O(1) - sadece pointer'lar kullanırız

Temel Optimizasyonlar:
1. Separate binary searches for first/last
2. Template-based approach for code reuse
3. Early termination if target not found
4. Boundary handling for edge cases

Key Insight: İki farklı binary search - biri sol boundary, diğeri sağ boundary
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int first = findFirst(nums, target);
        if (first == -1) return {-1, -1}; // Target bulunamadı
        
        int last = findLast(nums, target);
        return {first, last};
    }
    
private:
    // Target'ın ilk pozisyonunu bul (leftmost)
    int findFirst(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;        // Potansiyel sonuç kaydet
                right = mid - 1;     // Sol tarafa devam et (daha erken pozisyon ara)
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
    // Target'ın son pozisyonunu bul (rightmost)
    int findLast(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;        // Potansiyel sonuç kaydet
                left = mid + 1;      // Sağ tarafa devam et (daha geç pozisyon ara)
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
public:
    // Alternative Solution: Template-based approach
    vector<int> searchRangeTemplate(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        int first = binarySearchBound(nums, target, true);  // Find first
        if (first == -1) return {-1, -1};
        
        int last = binarySearchBound(nums, target, false);  // Find last
        return {first, last};
    }
    
private:
    // Template binary search for both first and last position
    int binarySearchBound(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                if (findFirst) {
                    right = mid - 1;  // Sol tarafa devam (first için)
                } else {
                    left = mid + 1;   // Sağ tarafa devam (last için)
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
public:
    // Alternative Solution: Single binary search + expand
    vector<int> searchRangeExpand(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        
        // Step 1: Normal binary search ile target'ı bul
        int pos = binarySearch(nums, target);
        if (pos == -1) return {-1, -1};
        
        // Step 2: Sol ve sağa expand et
        int left = pos, right = pos;
        
        // Sol tarafa expand
        while (left > 0 && nums[left - 1] == target) {
            left--;
        }
        
        // Sağ tarafa expand
        while (right < nums.size() - 1 && nums[right + 1] == target) {
            right++;
        }
        
        return {left, right};
    }
    
private:
    // Standard binary search
    int binarySearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        
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