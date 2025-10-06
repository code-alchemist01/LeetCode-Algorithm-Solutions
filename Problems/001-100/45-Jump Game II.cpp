/*
45. Jump Game II
Zorluk: Orta

Problem Açıklaması:
0-indexed integer array nums verildiğinde, başlangıçta index 0'dasınız.
Her nums[i] elementi i index'inden maksimum ileri atlama uzunluğunu temsil eder.
Index n-1'e ulaşmak için minimum atlama sayısını döndürün.

Örnek 1:
Giriş: nums = [2,3,1,1,4]
Çıkış: 2
Açıklama: Son index'e ulaşmak için minimum 2 atlama. 
Index 0'dan 1'e 1 adım, sonra son index'e 3 adım.

Örnek 2:
Giriş: nums = [2,3,0,1,4]
Çıkış: 2

Kısıtlamalar:
1 <= nums.length <= 10^4
0 <= nums[i] <= 1000
nums[n-1]'e ulaşabileceğiniz garanti edilir.

Strateji:
Greedy approach - her adımda mümkün olan en uzak noktaya ulaşmaya çalış.
BFS benzeri yaklaşım ile level by level ilerle.

Zaman Karmaşıklığı: O(n)
Alan Karmaşıklığı: O(1)
*/



class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }
        
        return jumps;
    }
};
