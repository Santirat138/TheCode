path="C:/Users/WIN11/Desktop/code/TheCode/Python/text.txt"
class Node:
    def __init__(self, textIn):
        self.text=textIn
        self.prev=None
        self.next=None

class LL:
    def __init__(self):
        self.amount=0
        self.head=None
        self.tail=None

    def show(self):
        currNode=self.head
        while currNode is not None:
            print(currNode.text)
            currNode=currNode.next
    
    def connectNode(self, nodeA, nodeB):
        nodeA.next=nodeB
        nodeB.prev=nodeA

    def addLast(self, newText):
        self.amount=self.amount+1
        newNode=Node(newText)
        if(self.head is None):
            self.head=newNode
        else:
            self.connectNode(self.tail, newNode)
        self.tail=newNode

def reader():
    ll=LL()
    file=open(path, 'r')
    array=[]
    for data in file:
        array.append(data.rstrip("\n"))
    file.close()
    arraySize=len(array)
    for currIdx in range(0, arraySize, +1):
        strLength=len(array[currIdx])
        newText=""
        for idx in range(0, strLength, +1):
            currCh=array[currIdx][idx]
            if(currCh!=" "):
                newText=newText+currCh
            else:
                ll.addLast(newText)
                newText=" "
        ll.addLast(newText)
    return ll

def makeBin(llIn):
    newLL=LL()
    currNode=llIn.head
    while currNode!=None:
        for idx in range(0, len(currNode.text), +1):
            newLL.addLast(str(bin(ord(currNode.text[idx]))[2:]))
        currNode=currNode.next
    return newLL



#       main
mainLL=reader()
numLL=makeBin(mainLL)
numLL.show()