class Node:
    num=-1
    next=None
    def __init__(this, newNum):
        this.num=newNum
        this.next=None

class LL:
    amount=0
    def __init__(this):
        this.amount=0
        this.head=None

    def addFirst(this, newNum):
        newNode=Node(newNum)
        if this.head!=None:
            newNode.next=this.head
        this.head=newNode

    def addLast(this, newNum):
        newNode=Node(newNum)
        if this.head==None:
            this.head=newNode
            return
        currNode=this.head
        while currNode.next!=None:
            currNode=currNode.next
        currNode.next=newNode

    def show(this):
        currNode=this.head
        while currNode!=None:
            print(currNode.num, " ")
            currNode=currNode.next

ll=LL()
for num in range(1, 10, 1):
    ll.addLast(num)

ll.show()