public class TEST {
    public static void main(String[] args) {
        
    }
}
class Node{
    int num;
    Node left;
    Node right;
    Node(int numIn){
        num=numIn;
    }
}
class BST{
    Node root;
    void preorderShow(Node root){
        if(root!=null){
            System.out.print(root.num+" ");
            preorderShow(root.left);
            preorderShow(root.right);
        }
    }
    void add(Node root, int newNum){
        if(root==null){
            root=new Node(newNum);
            return ;
        }
        if(newNum<root.num){
            
        }
    }
}