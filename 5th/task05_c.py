class ChainedList:
    def __init__ (self, value, tail) :
        self.value = value
        self.tail = tail

    def printList (self) :
        print(self.value, end = ' ')
        if (self.tail == None) : 
            print()
            return
        self.tail.printList()

    def addTail (self, value) :
        if (self.tail == None) : 
            self.tail = ChainedList(value, None)
            return
        self.tail.addTail(value)

    def insert (self, value, index) :
        if (index == 0) :
            ChainedList(value, self)
            self.tail = ChainedList(value, self.tail)
            return
        self.tail.insert(value, index - 1)

chainedList = ChainedList("I", None)

chainedList.addTail("am")
chainedList.addTail("a")
chainedList.addTail("pen")
chainedList.addTail(".")
chainedList.printList()

chainedList.insert("good", 3)
chainedList.printList()


