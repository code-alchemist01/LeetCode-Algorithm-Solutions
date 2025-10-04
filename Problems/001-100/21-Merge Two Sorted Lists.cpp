/*
21. Merge Two Sorted Lists
Easy

Problem: İki sıralı linked list'in head'leri verildiğinde, bunları tek bir 
sıralı liste halinde birleştir. Liste, ilk iki listenin node'larını 
splice ederek oluşturulmalı.

Strateji: Iterative Merge with Dummy Node
- Dummy node kullanarak edge case'leri basitleştir
- İki pointer ile her iki listeyi karşılaştır
- Küçük olanı seç ve ilerle
- Kalan node'ları sonuna ekle

Zaman Karmaşıklığı: O(m + n) - her node bir kez ziyaret edilir
Alan Karmaşıklığı: O(1) - sadece pointer'lar kullanılır

Temel Optimizasyonlar:
1. Dummy node pattern - head edge case'ini ortadan kaldırır
2. Single pass algoritması - her node sadece bir kez işlenir
3. In-place merging - yeni node oluşturmaz, mevcut node'ları kullanır
4. Tail pointer optimization - O(1) append işlemi
*/


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node - head edge case'ini basitleştirir
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Her iki liste de boş değilken karşılaştır ve merge et
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Kalan node'ları ekle (en fazla bir liste boş değil)
        tail->next = (list1 != nullptr) ? list1 : list2;
        
        // Dummy node'un next'i gerçek head'dir
        return dummy.next;
    }
};