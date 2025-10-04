/*
24. Swap Nodes in Pairs
Medium

Problem: Bir linked list verildiğinde, her iki komşu node'u swap et ve head'i return et.
Problemi node değerlerini değiştirmeden, sadece node'ların kendilerini değiştirerek çöz.

Strateji: Iterative Pointer Manipulation
- Dummy node kullanarak edge case'leri basitleştir
- Her iterasyonda iki node'u swap et
- Pointer'ları doğru şekilde yeniden bağla
- Tek node kaldığında dur

Zaman Karmaşıklığı: O(n) - her node bir kez ziyaret edilir
Alan Karmaşıklığı: O(1) - sadece pointer'lar kullanılır

Temel Optimizasyonlar:
1. Dummy node pattern - head edge case'ini ortadan kaldırır
2. Iterative approach - recursion stack'i kullanmaz
3. In-place swapping - extra space kullanmaz
4. Early termination - tek node kaldığında dur
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Edge case: boş liste veya tek node
        if (!head || !head->next) {
            return head;
        }
        
        // Dummy node - head değişimini kolaylaştırır
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Her iki node'u swap et
        while (prev->next && prev->next->next) {
            // Swap edilecek node'ları belirle
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Swap işlemi - pointer'ları yeniden bağla
            prev->next = second;        // prev -> second
            first->next = second->next; // first -> second'ın next'i
            second->next = first;       // second -> first
            
            // Bir sonraki çift için prev'i güncelle
            prev = first;
        }
        
        return dummy.next;
    }
};