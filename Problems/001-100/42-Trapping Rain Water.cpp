/*
42. Trapping Rain Water
Zorluk: Zor

Problem Açıklaması:
n negatif olmayan tamsayı verildiğinde, her çubuğun genişliği 1 olan bir yükseklik haritasını temsil eder.
Yağmur yağdıktan sonra ne kadar su tutulabileceğini hesaplayın.

Örnek 1:
Giriş: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Çıkış: 6
Açıklama: Yukarıdaki yükseklik haritası (siyah bölüm) [0,1,0,2,1,0,1,3,2,1,2,1] dizisi ile temsil edilir.
Bu durumda, 6 birim yağmur suyu (mavi bölüm) tutulur.

Örnek 2:
Giriş: height = [4,2,0,3,2,5]
Çıkış: 9

Kısıtlamalar:
n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5

Strateji:
Two Pointers yaklaşımı kullanarak sol ve sağdan ilerleyerek su miktarını hesapla.
Her pozisyonda tutulabilecek su = min(sol_max, sağ_max) - mevcut_yükseklik

Zaman Karmaşıklığı: O(n) - tek geçişte çözüm
Alan Karmaşıklığı: O(1) - sadece birkaç değişken kullanır
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                // Sol taraf daha düşük, sol tarafı işle
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                // Sağ taraf daha düşük veya eşit, sağ tarafı işle
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
};

/*
Algoritma Detayları:

Two Pointers Yaklaşımı:
1. Sol ve sağ pointer'ları başlat
2. Her adımda daha düşük tarafı işle
3. O(1) alan karmaşıklığı ile çözüm

Temel Mantık:
- Her pozisyonda tutulabilecek su = min(sol_max, sağ_max) - mevcut_yükseklik
- Daha düşük tarafı işleyerek min değerini garanti ederiz

Örnek Walkthrough (height = [0,1,0,2,1,0,1,3,2,1,2,1]):

Başlangıç: left=0, right=11, leftMax=0, rightMax=0, water=0

Adım 1: height[0]=0 < height[11]=1
        leftMax = max(0, 0) = 0
        water += 0 - 0 = 0, left=1

Adım 2: height[1]=1 = height[11]=1
        rightMax = max(0, 1) = 1
        water += 0, right=10

Adım 3: height[1]=1 < height[10]=2
        leftMax = max(0, 1) = 1
        water += 0, left=2

Adım 4: height[2]=0 < height[10]=2
        water += 1 - 0 = 1, left=3

Adım 5: height[3]=2 = height[10]=2
        rightMax = max(1, 2) = 2
        water += 0, right=9

...devam eder...

Sonuç: water = 6

Alternatif Yaklaşımlar:

1. Brute Force - O(n²):
   Her pozisyon için sol ve sağ maksimumu bul

2. Dynamic Programming - O(n) zaman, O(n) alan:
   Sol ve sağ maksimum dizilerini önceden hesapla

3. Stack - O(n) zaman, O(n) alan:
   Azalan yükseklikleri stack'te tut

4. Two Pointers - O(n) zaman, O(1) alan: ✅ En optimal

Kritik Optimizasyonlar:

1. Tek Geçiş: Diziyi sadece bir kez dolaş
2. Sabit Alan: Ekstra dizi kullanma
3. Erken Sonlandırma: left >= right olduğunda dur
4. Min Garantisi: Daha düşük tarafı işleyerek min(leftMax, rightMax) garanti et

Edge Cases:
- Boş dizi: 0 döndür
- Tek eleman: 0 döndür
- Tüm elemanlar aynı: 0 döndür
- Artan/azalan sıra: 0 döndür
*/