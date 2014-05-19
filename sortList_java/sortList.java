public class sortList {

	public static ListNode sort(ListNode head) {
		if (head == null || head.next == null) {
			return head;
		}
		ListNode middle = head, tail = head, pre = head;
		while (tail != null && tail.next != null) {
			pre = middle;
			middle = middle.next;
			tail = tail.next.next;
		}
		pre.next = null;
		ListNode h1 = sort(head);
		ListNode h2 = sort(middle);
		return merge(h1, h2);
	}

	public static ListNode merge(ListNode h1, ListNode h2) {
		ListNode head, tmp;
		;
		if (h1 == null) {
			return h2;
		}
		if (h2 == null) {
			return h1;
		}
		if (h1.val > h2.val) {
			head = h2;
			tmp = h2;
			h2 = h2.next;
		} else {
			head = h1;
			tmp = h1;
			h1 = h1.next;
		}
		while (h1 != null && h2 != null) {
			if (h1.val > h2.val) {
				tmp.next = h2;
				tmp = tmp.next;
				h2 = h2.next;
			} else {
				tmp.next = h1;
				tmp = tmp.next;
				h1 = h1.next;
			}
		}
		if (h1 == null) {
			tmp.next = h2;
		} else {
			tmp.next = h1;
		}
		return head;
	}

	public static void main(String[] args) {

		ListNode a = new ListNode(8);
		a.next = new ListNode(4);
		 a.next.next =new ListNode(2);
		ListNode b = sort(a);

		while (b != null) {
			System.out.println(b.val);
			b = b.next;
		}

	}
}
