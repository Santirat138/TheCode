public class Main {
    public static void main(String[] args) {
        RecLL recLL=new RecLL();
        recLL.add(1, 2, "name1", 50);
        recLL.add(5, 2, "name2", 40);
        recLL.add(1, 12, "name3", 90);
        recLL.show();
    }
}
class Date{
    int day;
    int month;
}
class Node{
    String moreInfo="-";
    Node next;
}
class RecNode extends Node{
    Date date;
    String detail;
    int price;
}
class RecLL{
    RecNode head;
    void show(){
        for(Node cNode=head;cNode!=null;cNode=cNode.next){
            System.out.println(((RecNode)cNode).date.day+"/"+((RecNode)cNode).date.month+": "+((RecNode)cNode).detail+", "+((RecNode)cNode).price);
        }
    }
    void add(int d, int m, String detail, int price){
        Date date=new Date();
        date.day=d;
        date.month=m;
        RecNode newNode=new RecNode();
        newNode.date=date;
        newNode.detail=detail;
        newNode.price=price;
        newNode.next=head;
        head=newNode;
    }
}
class RecTable{
    
}