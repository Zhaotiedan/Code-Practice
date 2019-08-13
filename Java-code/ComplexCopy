class Node{
    int val;
    Node next = null;
    Node random = null;

    Node(int val){
        this.val = val;
    }
}

public class ComplexCopy {

    //现有一单链表，每一个结点都有一个随机指向，可以指向任何结点，现需要将此链表进行深拷贝
    //深拷贝，不仅要将链表拷贝过来，还要将其背后的指向拷贝过来
    //1.先拷贝一份只有val和next指向链表p2.
    //2.将俩个链表p1和p2糅合在一个链表中：在p1不为空的情况下p2.next = p1.next; p1.next = p2;
    //再将p1指向head
    //3.进行random指向的拷贝：在p1不为空的情况下，p2.random = p1.random.next; p1 = p2.next; p2 = p1.next;
    //再将p1指向head
    //4.拆表：p1.next = p2.next; 在p2.next不为空的情况下p2.next = p2.next.next;反之p1 = p1.next;

    public static Node complexCopy(Node head){
        if(head == null){
            return null;
        }

        //糅合俩个链表
        Node p1 = head;
        while(p1 != null){
            Node p2 = new Node(p1.val);
            p2.next = p1.next;
            p1.next = p2;

            p1 = p2.next;
        }

        //2.复制random指向
        p1 = head;
        while(p1 != null){
            Node p2 = p1.next;
            if(p1.random != null) {
                p2.random = p1.random.next;
            }
            p1 = p2.next;
        }

        //3.拆表
        p1 = head;
        Node newHead = head.next;
        while(p1 != null) {
            Node p2 = p1.next;
            p1.next = p2.next;
            if (p2.next != null) {
                p2.next = p2.next.next;
            }
            p1 = p1.next;
        }
        return newHead;
    }

    public static void print(Node head){
        Node cur = head;
        while(cur != null){
            System.out.print(cur.val + "-->");
            cur = cur.next;
        }
        System.out.print("null");
        System.out.println();
    }

    public static void main(String[] args) {
        Node l1 = new Node(3);
        Node l2 = new Node(4);
        Node l3 = new Node(10);
        Node l4 = new Node(8);
        l1.next = l2;
        l2.next = l3;
        l3.next = l4;
        l1.random = l2;
        l2.random = l1;
        l3.random = l3;
        l4.random = null;

        print(complexCopy(l1));
        System.out.println((complexCopy(l1).random).val);





    }
}
