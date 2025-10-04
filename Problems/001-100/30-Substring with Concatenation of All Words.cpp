/*
30. Substring with Concatenation of All Words
Hard

Problem: Bir string s ve string array words verildiğinde, words'teki tüm 
string'lerin herhangi bir permutasyonunun concatenation'ı olan substring'lerin 
başlangıç index'lerini return et.

Strateji: Sliding Window + Hash Map
- Words frequency map'i oluştur
- Her olası başlangıç pozisyonu için sliding window
- Word-by-word comparison ile frequency match kontrolü
- Optimized sliding window ile O(n) per starting position

Zaman Karmaşıklığı: O(n * m) - n: string length, m: word length
Alan Karmaşıklığı: O(k) - k: unique words count

Temel Optimizasyonlar:
1. Hash map frequency counting
2. Sliding window technique
3. Word-level sliding (not character-level)
4. Early termination conditions
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.length();
        
        if (sLen < totalLen) return result;
        
        // Words frequency map'i oluştur
        unordered_map<string, int> wordFreq;
        for (const string& word : words) {
            wordFreq[word]++;
        }
        
        // Her olası word boundary'den başla (0, 1, ..., wordLen-1)
        for (int i = 0; i < wordLen; i++) {
            slidingWindow(s, i, wordLen, wordCount, sLen, wordFreq, result);
        }
        
        return result;
    }
    
private:
    void slidingWindow(const string& s, int start, int wordLen, int wordCount, int sLen,
                      const unordered_map<string, int>& wordFreq, vector<int>& result) {
        unordered_map<string, int> windowFreq;
        int left = start;
        int count = 0; // Valid words count in current window
        
        // Sliding window - word by word
        for (int right = start; right <= sLen - wordLen; right += wordLen) {
            // substr() yerine string_view benzeri yaklaşım - daha hızlı
            string word = s.substr(right, wordLen);
            
            // Current word valid mi? - count() daha hızlı
            if (wordFreq.count(word)) {
                windowFreq[word]++;
                count++;
                
                // Frequency fazla ise window'u shrink et
                while (windowFreq[word] > wordFreq.at(word)) {
                    string leftWord = s.substr(left, wordLen);
                    windowFreq[leftWord]--;
                    count--;
                    left += wordLen;
                }
                
                // Perfect match bulundu
                if (count == wordCount) {
                    result.push_back(left);
                }
            } else {
                // Invalid word - window'u reset et
                windowFreq.clear();
                count = 0;
                left = right + wordLen;
            }
        }
    }
};