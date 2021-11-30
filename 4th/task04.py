class MyClass:
    def __init__ (self, key, strings) :
        self.key = key
        self.strings = strings

    def printStatus (self) :
        print(self.key)
        print(self.strings)

myClass = MyClass (101, "name")

print(myClass.key)
print(myClass.strings)

myClass.printStatus()

