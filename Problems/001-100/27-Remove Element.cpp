/*
27. Remove Element
Easy

Problem: Bir integer array nums ve integer val verildiğinde, nums'tan val'in 
tüm occurrence'larını in-place olarak kaldır. Element'lerin sırası değişebilir. 
val'e eşit olmayan element sayısını return et.

Strateji: Two-Pointer Technique
- Left pointer: valid element'lerin yazılacağı pozisyon
- Right pointer: array'i traverse etmek için
- val'e eşit olmayan element'leri sol tarafa topla

Zaman Karmaşıklığı: O(n) - array'i bir kez traverse ederiz
Alan Karmaşıklığı: O(1) - sadece iki pointer kullanırız

Temel Optimizasyonlar:
1. Two-pointer approach - tek geçişte çözüm
2. In-place modification - extra space kullanmaz
3. Order flexibility - sıra önemli değil, daha esnek
4. Early termination - boş array kontrolü
*/


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Left pointer - valid element'lerin yazılacağı pozisyon
        int left = 0;
        
        // Right pointer ile array'i traverse et
        for (int right = 0; right < nums.size(); right++) {
            // val'e eşit olmayan element bulundu
            if (nums[right] != val) {
                nums[left] = nums[right];
                left++;
            }
            // val'e eşit ise skip et (left artmaz)
        }
        
        return left; // val'e eşit olmayan element sayısı
    }
};