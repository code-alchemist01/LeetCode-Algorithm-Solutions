/*
23. Merge k Sorted Lists
Hard

Problem: k tane sıralı linked list'in array'i verildiğinde, tüm linked list'leri 
tek bir sıralı linked list'e merge et ve return et.

Strateji: Divide and Conquer (Merge Sort Approach)
- k list'i ikili gruplar halinde merge et
- Her seviyede list sayısı yarıya iner
- Base case: 1 veya 0 list kaldığında dur
- mergeTwoLists fonksiyonunu yeniden kullan

Zaman Karmaşıklığı: O(N * log k) - N: toplam node sayısı, k: list sayısı
Alan Karmaşıklığı: O(log k) - recursion stack depth

Alternatif Yaklaşımlar:
1. Brute Force: O(N * k) - her seferinde minimum bul
2. Priority Queue: O(N * log k) - heap kullan
3. Divide & Conquer: O(N * log k) - optimal ve clean
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        // Divide and conquer ile merge et
        return mergeHelper(lists, 0, lists.size() - 1);
    }
    
private:
    // Divide and conquer helper function
    ListNode* mergeHelper(vector<ListNode*>& lists, int start, int end) {
        // Base case: tek list kaldı
        if (start == end) {
            return lists[start];
        }
        
        // Base case: hiç list yok
        if (start > end) {
            return nullptr;
        }
        
        // Divide: ortadan böl
        int mid = start + (end - start) / 2;
        
        // Conquer: sol ve sağ yarıları merge et
        ListNode* left = mergeHelper(lists, start, mid);
        ListNode* right = mergeHelper(lists, mid + 1, end);
        
        // Combine: iki sorted list'i merge et
        return mergeTwoLists(left, right);
    }
    
    // İki sorted linked list'i merge eden helper function
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        // Kalan node'ları ekle
        tail->next = list1 ? list1 : list2;
        
        return dummy.next;
    }
};