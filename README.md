# 🚀 LeetCode Journey - Algoritma Maceraları

Merhaba! 👋 Bu repo, LeetCode problemlerini çözerken öğrendiğim algoritmaları, veri yapılarını ve problem çözme stratejilerini paylaştığım kişisel yolculuğum.

## 🎯 Hedefim

Her problem sadece bir çözüm değil, aynı zamanda bir öğrenme deneyimi! Burada bulacağın şeyler:
- **Temiz ve anlaşılır kod** 📝
- **Detaylı açıklamalar** 🧠
- **Zaman/Alan karmaşıklığı analizleri** ⏱️
- **Farklı yaklaşımlar ve optimizasyonlar** 🔧
- **Gerçek hayat uygulamaları** 🌍

## 📊 İstatistikler

```
Toplam Çözülen Problem: 40
Kolay: 14 | Orta: 24 | Zor: 2
Kullanılan Diller: C++, Python
```

## 🛠️ Kullandığım Teknikler & Stratejiler

### 🔍 **Arama & Sıralama**
- **Binary Search**: Logaritmik zaman karmaşıklığı ile arama
- **Two Pointers**: O(n) zamanda array problemleri
- **Sliding Window**: Substring/subarray problemleri için

### 🌳 **Veri Yapıları**
- **Stack**: Parantez eşleştirme, expression evaluation
- **Hash Map/Set**: O(1) lookup, duplicate detection
- **Linked List**: Pointer manipülasyonu, cycle detection

### 🔄 **Algoritma Paradigmaları**
- **Backtracking**: Kombinasyon/permütasyon problemleri
- **Dynamic Programming**: Optimal substructure problemleri
- **Greedy**: Locally optimal choices
- **Divide & Conquer**: Problem bölme stratejisi

### 🎨 **Problem Çözme Patterns**
- **Fast & Slow Pointers**: Cycle detection
- **Multiple Pointers**: Array manipulation
- **Frequency Counter**: Character/element counting
- **Recursion**: Tree traversal, mathematical problems

## 📚 Problem Kategorileri

### 🔢 **Array & String Manipulation**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [1. Two Sum](Problems/001-100/01.py) | Kolay | Hash Map | Python | O(n) |
| [11. Container With Most Water](Problems/001-100/11-Container%20With%20Most%20Water.cpp) | Orta | Two Pointers | C++ | O(n) |
| [15. 3Sum](Problems/001-100/15-3Sum.cpp) | Orta | Two Pointers + Sort | C++ | O(n²) |
| [16. 3Sum Closest](Problems/001-100/16-3Sum%20Closest.cpp) | Orta | Two Pointers + Sort | C++ | O(n²) |
| [18. 4Sum](Problems/001-100/18-4Sum.cpp) | Orta | Multiple Pointers | C++ | O(n³) |
| [26. Remove Duplicates](Problems/001-100/26-Remove%20Duplicates%20from%20Sorted%20Array.cpp) | Kolay | Two Pointers | C++ | O(n) |
| [27. Remove Element](Problems/001-100/27-Remove%20Element.cpp) | Kolay | Two Pointers | C++ | O(n) |
| [31. Next Permutation](Problems/001-100/31-Next%20Permutation.cpp) | Orta | In-place Algorithm | C++ | O(n) |
| [33. Search in Rotated Array](Problems/001-100/33-Search%20in%20Rotated%20Sorted%20Array.cpp) | Orta | Modified Binary Search | C++ | O(log n) |
| [34. Find First and Last Position](Problems/001-100/34-Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array.cpp) | Orta | Binary Search | C++ | O(log n) |
| [35. Search Insert Position](Problems/001-100/35-Search%20Insert%20Position.cpp) | Kolay | Binary Search | C++ | O(log n) |
| [36. Valid Sudoku](Problems/001-100/36-Valid%20Sudoku.cpp) | Orta | Hash Set Validation | C++ | O(1) |

### 🔤 **String Processing**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [5. Longest Palindromic Substring](Problems/001-100/05.py) | Orta | Expand Around Centers | Python | O(n²) |
| [6. Zigzag Conversion](Problems/001-100/06-Zigzag%20Conversion.py) | Orta | Pattern Recognition | Python | O(n) |
| [8. String to Integer (atoi)](Problems/001-100/08-String%20to%20Integer%20(atoi).cpp) | Orta | State Machine | C++ | O(n) |
| [14. Longest Common Prefix](Problems/001-100/14-Longest%20Common%20Prefix.cpp) | Kolay | Vertical Scanning | C++ | O(S) |
| [20. Valid Parentheses](Problems/001-100/20-Valid%20Parentheses.cpp) | Kolay | Stack | C++ | O(n) |
| [28. Find First Occurrence](Problems/001-100/28-Find%20the%20Index%20of%20the%20First%20Occurrence%20in%20a%20String.cpp) | Kolay | KMP Algorithm | C++ | O(n+m) |
| [30. Substring with Concatenation](Problems/001-100/30-Substring%20with%20Concatenation%20of%20All%20Words.cpp) | Zor | Sliding Window + Hash | C++ | O(n×m×k) |
| [32. Longest Valid Parentheses](Problems/001-100/32-Longest%20Valid%20Parentheses.cpp) | Zor | Dynamic Programming | C++ | O(n) |
| [38. Count and Say](Problems/001-100/38-Count%20and%20Say.cpp) | Orta | String Building | C++ | O(n×m) |

### 🔢 **Mathematical & Logic**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [7. Reverse Integer](Problems/001-100/07-Reverse%20Integer.py) | Orta | Math + Overflow Check | Python | O(log n) |
| [9. Palindrome Number](Problems/001-100/09-Palindrome%20Number.cpp) | Kolay | Math (No String) | C++ | O(log n) |
| [12. Integer to Roman](Problems/001-100/12-Integer%20to%20Roman.cpp) | Orta | Greedy Algorithm | C++ | O(1) |
| [13. Roman to Integer](Problems/001-100/13-Roman%20to%20Integer.cpp) | Kolay | Pattern Recognition | C++ | O(n) |
| [29. Divide Two Integers](Problems/001-100/29-Divide%20Two%20Integers.cpp) | Orta | Bit Manipulation | C++ | O(log n) |

### 🔗 **Linked List Operations**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [2. Add Two Numbers](Problems/001-100/02.py) | Orta | Linked List Traversal | Python | O(max(m,n)) |
| [19. Remove Nth Node From End](Problems/001-100/19-Remove%20Nth%20Node%20From%20End%20of%20List.cpp) | Orta | Two Pointers | C++ | O(L) |
| [21. Merge Two Sorted Lists](Problems/001-100/21-Merge%20Two%20Sorted%20Lists.cpp) | Kolay | Dummy Node + Merge | C++ | O(m+n) |
| [23. Merge k Sorted Lists](Problems/001-100/23-Merge%20k%20Sorted%20Lists.cpp) | Zor | Divide & Conquer | C++ | O(n log k) |
| [24. Swap Nodes in Pairs](Problems/001-100/24-Swap%20Nodes%20in%20Pairs.cpp) | Orta | Iterative Swapping | C++ | O(n) |
| [25. Reverse Nodes in k-Group](Problems/001-100/25-Reverse%20Nodes%20in%20k-Group.cpp) | Zor | Group Reversal | C++ | O(n) |

### 🎯 **Backtracking & Recursion**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [17. Letter Combinations of Phone Number](Problems/001-100/17-Letter%20Combinations%20of%20a%20Phone%20Number.cpp) | Orta | Backtracking + DFS | C++ | O(3^m × 4^n) |
| [22. Generate Parentheses](Problems/001-100/22-Generate%20Parentheses.cpp) | Orta | Backtracking + Validation | C++ | O(4^n/√n) |
| [37. Sudoku Solver](Problems/001-100/37-Sudoku%20Solver.cpp) | Zor | Backtracking + Constraint | C++ | O(9^(n×n)) |
| [39. Combination Sum](Problems/001-100/39-Combination%20Sum.cpp) | Orta | Backtracking + Pruning | C++ | O(N^(T/M)) |
| [40. Combination Sum II](Problems/001-100/40-Combination%20Sum%20II.cpp) | Orta | Backtracking + Duplicate Skip | C++ | O(2^N) |

### 🔍 **Advanced Pattern Matching**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [10. Regular Expression Matching](Problems/001-100/10-Regular%20Expression%20Matching.cpp) | Zor | Dynamic Programming | C++ | O(m×n) |

## 💡 Problem Çözme Yaklaşımım

### 1. **Problemi Anlama** 🤔
- Input/Output formatını net anlama
- Edge case'leri belirleme
- Constraint'leri analiz etme

### 2. **Strateji Geliştirme** 🎯
- Brute force çözümden başlama
- Optimizasyon fırsatlarını arama
- Uygun veri yapısı/algoritma seçimi

### 3. **Implementasyon** ⚡
- Temiz ve okunabilir kod yazma
- Değişken isimlendirmesine dikkat etme
- Yorum satırları ile açıklama

### 4. **Test & Optimizasyon** 🧪
- Edge case'leri test etme
- Karmaşıklık analizi yapma
- Gerekirse refactoring

## 🎨 Kod Kalitesi Prensipleri

- **Readability First**: Kod önce insanlar için yazılır
- **Meaningful Names**: Değişken/fonksiyon isimleri açıklayıcı olmalı
- **Single Responsibility**: Her fonksiyon tek bir iş yapmalı
- **DRY Principle**: Don't Repeat Yourself
- **Comments**: Neden yaptığını açıkla, ne yaptığını değil

## 🚀 Gelecek Planları

- [ ] **Dynamic Programming** master'ı
- [ ] **Graph Algorithms** derinlemesine
- [ ] **Tree Traversal** teknikleri
- [ ] **Advanced Data Structures** (Trie, Segment Tree, etc.)
- [ ] **System Design** problemleri

## 📈 Öğrenme Kaynakları

- **LeetCode Patterns**: [14 Patterns to Ace Any Coding Interview](https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed)
- **Algorithm Visualizations**: [VisuAlgo](https://visualgo.net/)
- **Time Complexity**: [Big O Cheat Sheet](https://www.bigocheatsheet.com/)

## 🤝 Katkıda Bulunma

Bu repo kişisel öğrenme yolculuğum olsa da, önerileriniz her zaman hoş gelir! 
- Daha iyi bir çözüm bulduysanız
- Kod optimizasyonu öneriniz varsa  
- Açıklamalarda eksik gördüğünüz bir şey varsa

Issue açabilir veya pull request gönderebilirsiniz! 🎉
