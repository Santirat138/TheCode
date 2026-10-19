class Node:
    def __init__(this, newNum):
        this.num=newNum
        this.prev=None
        this.next=None

class LL:
    def __init__(this):
        this.head=None
        this.tail=None

    def showLL(this):
        currNode=this.head
        while currNode!=None:
            print(currNode.num)
            currNode=currNode.next
    
    def linkNode(this, nodeA, nodeB):
        nodeA.next=nodeB
        nodeB.prev=nodeA

    def addLast(this, newNum):
        newNode=Node(newNum)
        if this.head==None:
            this.head=newNode
        else:
            this.linkNode(this.tail, newNode)
        this.tail=newNode

ll=LL()
for num in range(1, 10, 1):
    ll.addLast(num)
ll.showLL()