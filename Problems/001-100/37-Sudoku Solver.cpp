/*
37. Sudoku Çözücü (Sudoku Solver)
Zorluk: Zor (Hard)

Boş hücreleri doldurarak bir Sudoku bulmacasını çözen program yazın.

Sudoku çözümü aşağıdaki tüm kuralları sağlamalıdır:
1. 1-9 arası her rakam, her satırda tam olarak bir kez bulunmalıdır.
2. 1-9 arası her rakam, her sütunda tam olarak bir kez bulunmalıdır.
3. 1-9 arası her rakam, 9 adet 3x3 alt kutunun her birinde tam olarak bir kez bulunmalıdır.

'.' karakteri boş hücreleri gösterir.

Örnek 1:
Giriş: board = [["5","3",".",".","7",".",".",".","."],
                ["6",".",".","1","9","5",".",".","."],
                [".","9","8",".",".",".",".","6","."],
                ["8",".",".",".","6",".",".",".","3"],
                ["4",".",".","8",".","3",".",".","1"],
                ["7",".",".",".","2",".",".",".","6"],
                [".","6",".",".",".",".","2","8","."],
                [".",".",".","4","1","9",".",".","5"],
                [".",".",".",".","8",".",".","7","9"]]

Çıkış: [["5","3","4","6","7","8","9","1","2"],
        ["6","7","2","1","9","5","3","4","8"],
        ["1","9","8","3","4","2","5","6","7"],
        ["8","5","9","7","6","1","4","2","3"],
        ["4","2","6","8","5","3","7","9","1"],
        ["7","1","3","9","2","4","8","5","6"],
        ["9","6","1","5","3","7","2","8","4"],
        ["2","8","7","4","1","9","6","3","5"],
        ["3","4","5","2","8","6","1","7","9"]]

Kısıtlamalar:
- board.length == 9
- board[i].length == 9
- board[i][j] bir rakam veya '.' karakteridir
- Giriş tahtasının yalnızca bir çözümü olduğu garanti edilir.

Strateji: Geri İzleme Algoritması (Backtracking Algorithm)
1. Boş bir hücre bul ('.')
2. O hücrede 1-9 arası rakamları dene
3. Rakamın geçerli olup olmadığını kontrol et (Sudoku kurallarını ihlal etmez)
4. Geçerliyse, tahtanın geri kalanını özyinelemeli olarak çöz
5. Çözüm bulunamazsa, geri git ve bir sonraki rakamı dene
6. Tüm rakamlar başarısız olursa, false döndür (daha da geri git)

Zaman Karmaşıklığı: O(9^(n*n)) burada n=9, en kötü durum tahta boş olduğunda
Alan Karmaşıklığı: O(n*n) en kötü durumda özyineleme yığını için
*/


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            
                            if (solve(board)) {
                                return true;
                            }
                            
                            board[row][col] = '.'; // Geri git
                        }
                    }
                    return false; // Geçerli rakam bulunamadı
                }
            }
        }
        return true; // Tüm hücreler dolduruldu
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        // Satırı kontrol et
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == num) return false;
        }
        
        // Sütunu kontrol et
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == num) return false;
        }
        
        // 3x3 kutuyu kontrol et
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int i = boxRow; i < boxRow + 3; i++) {
            for (int j = boxCol; j < boxCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        
        return true;
    }
};

// Alternatif Çözüm: Kısıt izleme ile optimize edilmiş
class SolutionOptimized {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Kısıt izleme dizilerini başlat
        bool rows[9][9] = {false};    // rows[i][d-1] = true eğer d rakamı i satırında varsa
        bool cols[9][9] = {false};    // cols[j][d-1] = true eğer d rakamı j sütununda varsa
        bool boxes[9][9] = {false};   // boxes[box][d-1] = true eğer d rakamı kutuda varsa
        
        // Mevcut rakamlarla kısıt dizilerini doldur
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    int box = (i / 3) * 3 + j / 3;
                    rows[i][digit] = true;
                    cols[j][digit] = true;
                    boxes[box][digit] = true;
                }
            }
        }
        
        backtrackOptimized(board, rows, cols, boxes);
    }
    
private:
    bool backtrackOptimized(vector<vector<char>>& board, 
                           bool rows[9][9], bool cols[9][9], bool boxes[9][9]) {
        // En az olasılığa sahip boş hücreyi bul (MRV sezgiseli)
        int minRow = -1, minCol = -1, minChoices = 10;
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int choices = countChoices(i, j, rows, cols, boxes);
                    if (choices < minChoices) {
                        minChoices = choices;
                        minRow = i;
                        minCol = j;
                    }
                }
            }
        }
        
        // Boş hücre bulunamazsa, bulmaca çözülmüştür
        if (minRow == -1) return true;
        
        // Seçilen hücre için tüm geçerli rakamları dene
        int box = (minRow / 3) * 3 + minCol / 3;
        for (int digit = 0; digit < 9; digit++) {
            if (!rows[minRow][digit] && !cols[minCol][digit] && !boxes[box][digit]) {
                // Rakamı yerleştir
                board[minRow][minCol] = '1' + digit;
                rows[minRow][digit] = true;
                cols[minCol][digit] = true;
                boxes[box][digit] = true;
                
                // Özyinelemeli çağrı
                if (backtrackOptimized(board, rows, cols, boxes)) {
                    return true;
                }
                
                // Geri git
                board[minRow][minCol] = '.';
                rows[minRow][digit] = false;
                cols[minCol][digit] = false;
                boxes[box][digit] = false;
            }
        }
        
        return false;
    }
    
    // Bir hücre için geçerli seçenekleri say (MRV - Minimum Kalan Değerler sezgiseli)
    int countChoices(int row, int col, bool rows[9][9], bool cols[9][9], bool boxes[9][9]) {
        int box = (row / 3) * 3 + col / 3;
        int count = 0;
        
        for (int digit = 0; digit < 9; digit++) {
            if (!rows[row][digit] && !cols[col][digit] && !boxes[box][digit]) {
                count++;
            }
        }
        
        return count;
    }
};

// Alternatif Çözüm: Daha hızlı kısıt kontrolü için bit manipülasyonu
class SolutionBitMask {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};    // Her satır için bit maskesi
        int cols[9] = {0};    // Her sütun için bit maskesi
        int boxes[9] = {0};   // Her kutu için bit maskesi
        
        // Bit maskelerini başlat
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    int bit = 1 << digit;
                    int box = (i / 3) * 3 + j / 3;
                    
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[box] |= bit;
                }
            }
        }
        
        backtrackBitMask(board, rows, cols, boxes);
    }
    
private:
    bool backtrackBitMask(vector<vector<char>>& board, 
                         int rows[9], int cols[9], int boxes[9]) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    int box = (i / 3) * 3 + j / 3;
                    
                    for (int digit = 0; digit < 9; digit++) {
                        int bit = 1 << digit;
                        
                        // Bitwise işlemler kullanarak rakamın geçerli olup olmadığını kontrol et
                        if (!(rows[i] & bit) && !(cols[j] & bit) && !(boxes[box] & bit)) {
                            // Rakamı yerleştir
                            board[i][j] = '1' + digit;
                            rows[i] |= bit;
                            cols[j] |= bit;
                            boxes[box] |= bit;
                            
                            // Özyinelemeli çağrı
                            if (backtrackBitMask(board, rows, cols, boxes)) {
                                return true;
                            }
                            
                            // Geri git
                            board[i][j] = '.';
                            rows[i] &= ~bit;
                            cols[j] &= ~bit;
                            boxes[box] &= ~bit;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};

