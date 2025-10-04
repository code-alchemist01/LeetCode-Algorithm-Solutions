/*
26. Remove Duplicates from Sorted Array
Easy

Problem: Non-decreasing order'da sıralanmış bir integer array'den duplicate'ları 
in-place olarak kaldır. Her unique element sadece bir kez görünmeli. Relative 
order korunmalı. Unique element sayısını return et.

Strateji: Two-Pointer Technique
- Slow pointer: unique element'lerin yazılacağı pozisyon
- Fast pointer: array'i traverse etmek için
- Sorted array olduğu için duplicate'lar yan yana

Zaman Karmaşıklığı: O(n) - array'i bir kez traverse ederiz
Alan Karmaşıklığı: O(1) - sadece iki pointer kullanırız

Temel Optimizasyonlar:
1. Two-pointer approach - tek geçişte çözüm
2. In-place modification - extra space kullanmaz
3. Early termination - boş array kontrolü
4. Sorted array advantage - duplicate'lar yan yana
*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Edge case: boş array
        if (nums.empty()) return 0;
        
        // Slow pointer - unique element'lerin yazılacağı pozisyon
        int slow = 1; // İlk element zaten unique
        
        // Fast pointer - array'i traverse et
        for (int fast = 1; fast < nums.size(); fast++) {
            // Yeni unique element bulundu
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        
        return slow; // Unique element sayısı
    }
};