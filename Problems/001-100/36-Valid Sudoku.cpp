/*
36. Valid Sudoku
Medium

Problem: 9x9 Sudoku board'un valid olup olmadığını kontrol et.
Sadece dolu hücreler validate edilecek:
1. Her satır 1-9 rakamlarını tekrarsız içermeli
2. Her sütun 1-9 rakamlarını tekrarsız içermeli  
3. Her 3x3 sub-box 1-9 rakamlarını tekrarsız içermeli

Strateji: Hash Set with Smart Encoding
1. Her hücre için row, column, box kontrolü yap
2. Unique string encoding ile duplicate detection
3. Single pass ile tüm kuralları kontrol et
4. Box index calculation: (row/3)*3 + col/3

Zaman Karmaşıklığı: O(1) - 9x9 fixed size board
Alan Karmaşıklığı: O(1) - maximum 27 sets with 9 elements each

Temel Optimizasyonlar:
1. Single pass validation - one loop through board
2. Smart string encoding - unique identifiers
3. Early termination - return false immediately
4. Efficient box indexing - mathematical formula
*/

class Solution {
public:
    // OPTIMIZED: Fast boolean arrays instead of slow string operations
    bool isValidSudoku(vector<vector<char>>& board) {
        // Arrays to track seen numbers - much faster than string hash sets
        bool rows[9][9] = {false};    // rows[i][num-1] = true if num seen in row i
        bool cols[9][9] = {false};    // cols[j][num-1] = true if num seen in col j
        bool boxes[9][9] = {false};   // boxes[box][num-1] = true if num seen in box
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '1';  // Convert '1'-'9' to 0-8 (fast)
                int box = (i / 3) * 3 + j / 3;  // Box index calculation (fast)
                
                // Check if number already seen - direct array access (O(1))
                if (rows[i][num] || cols[j][num] || boxes[box][num]) {
                    return false;
                }
                
                // Mark number as seen - direct assignment (fast)
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }
        
        return true;
    }
    
    // Alternative Solution: Separate arrays for each constraint
    bool isValidSudokuArrays(vector<vector<char>>& board) {
        // Arrays to track seen numbers
        bool rows[9][9] = {false};    // rows[i][num-1] = true if num seen in row i
        bool cols[9][9] = {false};    // cols[j][num-1] = true if num seen in col j
        bool boxes[9][9] = {false};   // boxes[box][num-1] = true if num seen in box
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '1';  // Convert '1'-'9' to 0-8
                int box = (i / 3) * 3 + j / 3;  // Box index calculation
                
                // Check if number already seen in row, column, or box
                if (rows[i][num] || cols[j][num] || boxes[box][num]) {
                    return false;
                }
                
                // Mark number as seen
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }
        
        return true;
    }
    
    // Alternative Solution: Bit manipulation approach (FASTEST)
    bool isValidSudokuBits(vector<vector<char>>& board) {
        // Use integers as bit arrays (9 bits for digits 1-9) - most memory efficient
        int rows[9] = {0};    // Bit array for each row
        int cols[9] = {0};    // Bit array for each column
        int boxes[9] = {0};   // Bit array for each box
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                
                int num = board[i][j] - '1';  // Convert to 0-8
                int bit = 1 << num;           // Create bit mask (fastest)
                int box = (i / 3) * 3 + j / 3;
                
                // Check if bit already set - bitwise AND operation (fastest)
                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[box] & bit)) {
                    return false;
                }
                
                // Set the bit - bitwise OR operation (fastest)
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
            }
        }
        
        return true;
    }
    
    // Alternative Solution: Validation by separate functions
    bool isValidSudokuSeparate(vector<vector<char>>& board) {
        return isValidRows(board) && isValidCols(board) && isValidBoxes(board);
    }
    
private:
    bool isValidRows(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (seen.count(board[i][j])) return false;
                    seen.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    
    bool isValidCols(vector<vector<char>>& board) {
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (seen.count(board[i][j])) return false;
                    seen.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    
    bool isValidBoxes(vector<vector<char>>& board) {
        for (int box = 0; box < 9; box++) {
            unordered_set<char> seen;
            int startRow = (box / 3) * 3;
            int startCol = (box % 3) * 3;
            
            for (int i = startRow; i < startRow + 3; i++) {
                for (int j = startCol; j < startCol + 3; j++) {
                    if (board[i][j] != '.') {
                        if (seen.count(board[i][j])) return false;
                        seen.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};