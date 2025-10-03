/*
Container With Most Water - Two Pointers Greedy Yaklaşımı

Bu problemde iki çubuk arasında maksimum su tutabilecek alanı buluyoruz.
Alan = min(height[left], height[right]) * (right - left)

Temel Mantık:
İki pointer kullanarak baştan ve sondan başlıyoruz. Neden bu çalışıyor?
- Geniş mesafe her zaman avantajlı başlangıç
- Kısa olan çubuğu hareket ettirmek mantıklı çünkü:
  * Uzun olanı hareket ettirirsek mesafe azalır ama yükseklik aynı kalır
  * Kısa olanı hareket ettirirsek daha yüksek bir çubuk bulma şansımız var

Greedy Seçim Kanıtı:
Diyelim left < right ve height[left] < height[right]
- Eğer right'ı hareket ettirirsek: mesafe azalır, yükseklik max height[left] olur
- Eğer left'ı hareket ettirirsek: mesafe azalır ama yükseklik artabilir
Bu yüzden her zaman kısa olanı hareket ettirmek optimal!

Time: O(n) - her element'i bir kez ziyaret
Space: O(1) - sadece iki pointer
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, m = 0;
        
        while (l < r) {
            int area = (height[l] < height[r] ? height[l] : height[r]) * (r - l);
            if (area > m) m = area;
            height[l] < height[r] ? ++l : --r;
        }
        
        return m;
    }
};