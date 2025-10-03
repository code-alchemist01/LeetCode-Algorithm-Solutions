/*
19. Remove Nth Node From End of List
Medium

Problem: Bağlı listenin head'i verildiğinde, sondan n'inci düğümü kaldır ve 
listenin head'ini döndür.

Strateji: Two-Pointer Tekniği (Fast & Slow)
- Fast pointer'ı n adım ilerlet
- Sonra her iki pointer'ı birlikte hareket ettir
- Fast pointer sona ulaştığında, slow pointer silinecek düğümün öncesinde olur
- Dummy node kullanarak edge case'leri handle et

Zaman Karmaşıklığı: O(L) - L: liste uzunluğu, tek geçişte çözüm
Alan Karmaşıklığı: O(1) - sadece sabit alan kullanımı

Temel Optimizasyonlar:
1. Tek geçiş algoritması - liste boyutunu önceden bilmeye gerek yok
2. Dummy node - head silinmesi durumunu handle eder
3. Two-pointer tekniği - elegant ve efficient çözüm
4. Edge case handling - tek node, head silme gibi durumlar
*/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node oluştur - head silinmesi durumunu handle eder
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // Fast pointer'ı n+1 adım ilerlet
        // Bu sayede slow pointer silinecek düğümün öncesinde kalır
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Her iki pointer'ı birlikte hareket ettir
        // Fast pointer sona ulaştığında, slow pointer doğru pozisyonda olur
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        // Silinecek düğümü kaydet ve bağlantıyı güncelle
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // Belleği temizle (optional, LeetCode'da gerekli değil)
        delete nodeToDelete;
        
        return dummy.next;
    }
};