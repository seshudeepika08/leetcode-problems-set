class Solution:
    def reverseKGroup(self, head, k):
        def get_kth(curr, k):
            while curr and k > 0:
                curr = curr.next
                k -= 1
            return curr

        dummy = ListNode(0)
        dummy.next = head
        group_prev = dummy

        while True:
            kth = get_kth(group_prev, k)
            if not kth:
                break

            group_next = kth.next

            # Reverse group
            prev, curr = kth.next, group_prev.next
            while curr != group_next:
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp

            # Connect with previous part
            temp = group_prev.next
            group_prev.next = kth
            group_prev = temp

        return dummy.next