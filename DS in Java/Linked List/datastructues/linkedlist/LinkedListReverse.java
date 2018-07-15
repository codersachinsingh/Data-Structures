package datastructues.linkedlist;

public class LinkedList {
    public Node insert(Node head , int data) {
        if (head == null)
            return new Node(data);
        else {
            head.next = insert(head.next,data);
            return head;
        }
    }

    public void traverse(Node head) {
        if (head == null)
            return;
        System.out.println(head);
        traverse(head.next);
    }

    public Node reverselist(Node head) {
        Node newHead = null;
        while(head != null) {
            Node nextNode  = head.next;
            head.next = newHead;
            newHead = head;
            head = nextNode;
        }
        return newHead;
    }
}
