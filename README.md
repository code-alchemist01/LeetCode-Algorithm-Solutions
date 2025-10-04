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
Toplam Çözülen Problem: 21
Kolay: 9 | Orta: 10 | Zor: 2
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
| [18. 4Sum](Problems/001-100/18-4Sum.cpp) | Orta | Multiple Pointers | C++ | O(n³) |

### 🔤 **String Processing**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [5. Longest Palindromic Substring](Problems/001-100/05.py) | Orta | Expand Around Centers | Python | O(n²) |
| [6. Zigzag Conversion](Problems/001-100/06-Zigzag%20Conversion.py) | Orta | Pattern Recognition | Python | O(n) |
| [14. Longest Common Prefix](Problems/001-100/14-Longest%20Common%20Prefix.cpp) | Kolay | Vertical Scanning | C++ | O(S) |
| [20. Valid Parentheses](Problems/001-100/20-Valid%20Parentheses.cpp) | Kolay | Stack | C++ | O(n) |

### 🔢 **Mathematical & Logic**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [7. Reverse Integer](Problems/001-100/07-Reverse%20Integer.py) | Orta | Math + Overflow Check | Python | O(log n) |
| [9. Palindrome Number](Problems/001-100/09-Palindrome%20Number.cpp) | Kolay | Math (No String) | C++ | O(log n) |
| [12. Integer to Roman](Problems/001-100/12-Integer%20to%20Roman.cpp) | Orta | Greedy Algorithm | C++ | O(1) |
| [13. Roman to Integer](Problems/001-100/13-Roman%20to%20Integer.cpp) | Kolay | Pattern Recognition | C++ | O(n) |

### 🔗 **Linked List Operations**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [2. Add Two Numbers](Problems/001-100/02.py) | Orta | Linked List Traversal | Python | O(max(m,n)) |
| [19. Remove Nth Node From End](Problems/001-100/19-Remove%20Nth%20Node%20From%20End%20of%20List.cpp) | Orta | Two Pointers | C++ | O(L) |
| [21. Merge Two Sorted Lists](Problems/001-100/21-Merge%20Two%20Sorted%20Lists.cpp) | Kolay | Dummy Node + Merge | C++ | O(m+n) |

### 🎯 **Backtracking & Recursion**
| Problem | Zorluk | Teknik | Dil | Karmaşıklık |
|---------|--------|--------|-----|-------------|
| [17. Letter Combinations of Phone Number](Problems/001-100/17-Letter%20Combinations%20of%20a%20Phone%20Number.cpp) | Orta | Backtracking + DFS | C++ | O(3^m × 4^n) |

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
