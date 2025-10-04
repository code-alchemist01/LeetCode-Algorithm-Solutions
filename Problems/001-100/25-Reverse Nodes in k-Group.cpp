/*
25. Reverse Nodes in k-Group
Hard

Problem: Bir linked list'in head'i verildiğinde, listedeki node'ları k'şar k'şar 
reverse et ve modified list'i return et. k pozitif bir integer ve linked list'in 
uzunluğundan küçük veya eşit. Eğer node sayısı k'nın katı değilse, sonda kalan 
node'lar olduğu gibi kalmalı.

Strateji: Iterative Group Reversal
- Her k-group'u identify et
- Her group'u ayrı ayrı reverse et
- Group'ları birbirine bağla
- Kalan node'ları olduğu gibi bırak

Zaman Karmaşıklığı: O(n) - her node bir kez ziyaret edilir
Alan Karmaşıklığı: O(1) - sadece pointer'lar kullanılır

Temel Optimizasyonlar:
1. Dummy node pattern - head edge case'ini basitleştir
2. Group length checking - k node var mı kontrol et
3. Iterative reversal - recursion stack kullanma
4. Pointer manipulation - in-place reversal
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        
        // Dummy node - head değişimini kolaylaştırır
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroupEnd = &dummy;
        
        while (true) {
            // k node var mı kontrol et
            ListNode* kthNode = getKthNode(prevGroupEnd, k);
            if (!kthNode) break;
            
            ListNode* nextGroupStart = kthNode->next;
            
            // Current group'u reverse et
            ListNode* prev = nextGroupStart;
            ListNode* curr = prevGroupEnd->next;
            
            // k node'u reverse et
            while (curr != nextGroupStart) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            // Group'ları birbirine bağla
            ListNode* temp = prevGroupEnd->next;
            prevGroupEnd->next = kthNode;
            prevGroupEnd = temp;
        }
        
        return dummy.next;
    }
    
private:
    // prevGroupEnd'den k adım ilerle, k'ıncı node'u return et
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};