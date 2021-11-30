
class Node :
    def __init__ (self, value, tail) :
        self.value = value
        self.tail = tail

    def getNodeOf (self, index) :
        if (index == 0) : return self
        return self.tail.getNodeOf(index - 1)
    
    def getPrevOf (self, index) :
        if (index == 1) : return self
        return self.tail.getPrevOf(index - 1)

    def getTailNode (self) :
        if (self.tail == None) : return self
        return self.tail.getTailNode()
    
class ChainedList:

    def __init__ (self, value) :
        node = Node(value, None)
        self.head = node
    
    def addHead (self, value) :
        node = Node(value, self.head)
        self.head = node

    def addTail (self, value) :
        self.head.getTailNode().tail = Node(value, None)

    def insert (self, value, index) :
        if (index == 0) : 
            self.addHead(value)
            return
        if (index < 0) :
            self.addTail(value)
            return
        target = self.head.getPrevOf(index)
        node = Node(value, target.tail)
        target.tail = node

    def printValues (self) :
        target = self.head
        while (target != None) :
            print(target.value, end = ' ')
            target = target.tail
        print()

    def printNodeOf (self, index) :
        print(self.head.getNodeOf(index).value)

chainedList = ChainedList("I")
chainedList.printValues()

chainedList.insert("am", -1)
chainedList.insert("a", -1)
chainedList.insert("pen", -1)
chainedList.insert(".", -1)
chainedList.printValues()

chainedList.insert("Hello!", 0)
chainedList.printValues()

chainedList.insert("nice", 4) 
chainedList.printValues()

chainedList.insert("bye!", -1)
chainedList.printValues()

