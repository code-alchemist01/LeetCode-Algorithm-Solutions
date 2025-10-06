/*
41. First Missing Positive
Zorluk: Zor

Problem Açıklaması:
Sıralanmamış bir tamsayı dizisi nums verildiğinde, nums'ta bulunmayan en küçük pozitif tamsayıyı döndürün.
O(n) zamanda çalışan ve O(1) yardımcı alan kullanan bir algoritma uygulamalısınız.

Örnek 1:
Giriş: nums = [1,2,0]
Çıkış: 3
Açıklama: [1,2] aralığındaki sayılar dizide mevcut.

Örnek 2:
Giriş: nums = [3,4,-1,1]
Çıkış: 2
Açıklama: 1 dizide var ama 2 eksik.

Örnek 3:
Giriş: nums = [7,8,9,11,12]
Çıkış: 1
Açıklama: En küçük pozitif tamsayı 1 eksik.

Kısıtlamalar:
1 <= nums.length <= 10^5
-2^31 <= nums[i] <= 2^31 - 1

Strateji:
Cyclic Sort yaklaşımı kullanarak her pozitif sayıyı doğru pozisyonuna yerleştir.
Sonra ilk eksik pozisyonu bul.

Zaman Karmaşıklığı: O(n) - her eleman en fazla bir kez taşınır
Alan Karmaşıklığı: O(1) - sadece in-place swap kullanır
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Adım 1: Cyclic Sort - her sayıyı doğru pozisyonuna yerleştir
        // nums[i] = i+1 olmalı (1-indexed)
        for (int i = 0; i < n; i++) {
            // nums[i] pozitif, n'den küçük veya eşit ve doğru pozisyonda değilse
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // nums[i]'yi doğru pozisyonuna taşı
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Adım 2: İlk eksik pozitif sayıyı bul
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Tüm 1'den n'e kadar sayılar mevcut, n+1 döndür
        return n + 1;
    }
};

/*
Algoritma Detayları:

1. Cyclic Sort Yaklaşımı:
   - Her pozitif sayı nums[i]'yi index (nums[i]-1)'e yerleştir
   - Sadece 1 <= nums[i] <= n aralığındaki sayılarla ilgilen
   - Negatif sayılar ve n'den büyük sayılar önemli değil

2. Swap Koşulları:
   - nums[i] > 0: Pozitif olmalı
   - nums[i] <= n: Dizinin boyutundan küçük veya eşit olmalı
   - nums[nums[i] - 1] != nums[i]: Hedef pozisyonda farklı sayı olmalı

3. Sonuç Bulma:
   - İlk i pozisyonunda nums[i] != i+1 olan yeri bul
   - Bu i+1 eksik olan en küçük pozitif sayıdır

Örnek Walkthrough (nums = [3,4,-1,1]):

Başlangıç: [3, 4, -1, 1]
           i=0  1   2   3

i=0: nums[0]=3, 3'ü index 2'ye yerleştir
     swap(nums[0], nums[2]) → [-1, 4, 3, 1]
     nums[0]=-1, negatif olduğu için dur

i=1: nums[1]=4, 4'ü index 3'e yerleştir
     swap(nums[1], nums[3]) → [-1, 1, 3, 4]
     nums[1]=1, 1'i index 0'a yerleştir
     swap(nums[1], nums[0]) → [1, -1, 3, 4]
     nums[1]=-1, negatif olduğu için dur

i=2: nums[2]=3, zaten doğru pozisyonda (index 2)

i=3: nums[3]=4, zaten doğru pozisyonda (index 3)

Sonuç: [1, -1, 3, 4]
       index 1'de -1 var, 2 olmalıydı
       Cevap: 2

Kritik Optimizasyonlar:

1. While Loop: Bir pozisyonda birden fazla swap gerekebilir
2. Duplicate Check: nums[nums[i] - 1] != nums[i] ile sonsuz döngüyü önle
3. Range Check: Sadece [1, n] aralığındaki sayılarla ilgilen
4. In-place: Ekstra alan kullanmadan çözüm
*/