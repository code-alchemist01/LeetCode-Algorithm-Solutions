
/*
18. 4Sum
Medium

Problem: n tamsayıdan oluşan nums dizisi verildiğinde, toplamları target'a eşit olan
tüm benzersiz dörtlüleri [nums[a], nums[b], nums[c], nums[d]] döndür.

Strateji: Sıralama + İki Pointer Tekniği
- Diziyi sırala ve 4 nested loop yerine 2 nested + 2 pointer kullan
- Duplicate'ları atla ve erken sonlandırma optimizasyonları uygula
- 3Sum'ın genişletilmiş versiyonu

Zaman Karmaşıklığı: O(n³) - 2 nested loop + 2 pointer
Alan Karmaşıklığı: O(1) - sadece sabit alan kullanımı (sonuç hariç)

Temel Optimizasyonlar:
1. Erken sonlandırma - minimum/maksimum değer kontrolleri
2. Duplicate skipping - aynı değerleri atla
3. Two-pointer tekniği - O(n) yerine O(n²) inner loop
4. Integer overflow kontrolü - long long kullanımı
5. Cache-friendly sıralı erişim
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        
        for (int i = 0; i < n - 3; ++i) {
            // İlk eleman için duplicate'ları atla
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // Erken sonlandırma - minimum değer çok büyük
            if ((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            
            // Erken sonlandırma - maksimum değer çok küçük
            if ((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;
            
            for (int j = i + 1; j < n - 2; ++j) {
                // İkinci eleman için duplicate'ları atla
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                
                // Erken sonlandırma - minimum değer çok büyük
                if ((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                
                // Erken sonlandırma - maksimum değer çok küçük
                if ((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;
                
                int left = j + 1, right = n - 1;
                long long twoSum = (long long)target - nums[i] - nums[j];
                
                while (left < right) {
                    long long currentSum = (long long)nums[left] + nums[right];
                    
                    if (currentSum == twoSum) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        // Üçüncü eleman için duplicate'ları atla
                        do { ++left; } while (left < right && nums[left] == nums[left-1]);
                        
                        // Dördüncü eleman için duplicate'ları atla
                        do { --right; } while (left < right && nums[right] == nums[right+1]);
                    }
                    else if (currentSum < twoSum) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }
        }
        
        return result;
    }
};