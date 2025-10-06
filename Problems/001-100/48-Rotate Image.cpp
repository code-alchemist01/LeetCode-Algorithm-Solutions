/*
48. Rotate Image
Zorluk: Orta

Problem Açıklaması:
n x n 2D matrix ile temsil edilen bir görüntü verildiğinde, 
görüntüyü 90 derece saat yönünde döndürün.

Görüntüyü yerinde döndürmeniz gerekir, yani 2D matrisi doğrudan değiştirin. 
Başka bir 2D matrix tahsis etmeyin ve rotasyonu yapmayın.

Örnek 1:
Giriş: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Çıkış: [[7,4,1],[8,5,2],[9,6,3]]

Örnek 2:
Giriş: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Çıkış: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Kısıtlamalar:
n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000

Strateji:
1. Transpose matrix (satır ve sütunları değiştir)
2. Her satırı reverse et

Zaman Karmaşıklığı: O(n²)
Alan Karmaşıklığı: O(1)
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Step 1: Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
