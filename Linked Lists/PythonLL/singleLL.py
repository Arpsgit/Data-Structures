class element:
    def __init__(self, data = None, next = None):
        self.data = data
        self.next = next

class linkedList:
    def __init__(self):
        self.head = None
    def createList(self):
        while True:
            data = int(input("Enter the element: "))
            node = element(data)
            if self.head is None:
                self.head = node
                temp = self.head
            else:
                temp.next = node
                temp = node
            x = input("Want to continue (y/n): ")
            if x == 'n':
                break
    def insertBegin(self, data):
        node = element(data, self.head)
        self.head = node
    def insertEnd(self, data):
        node = element(data)
        if self.head is None:
            self.head = node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = node
    def display(self):
        if self.head is None:
            print("The List is Empty!!!")
            return
        temp = self.head
        print("The List is: ")
        while temp:
            print(f"{temp.data} ")
            temp = temp.next
    def deleteBegin(self):
        if self.head is None:
            print("The List is Empty!!!")
            return
        self.head = self.head.next
    def deleteEnd(self):
        if self.head is None:
            print("The List is Empty!!!")
            return
        temp = self.head
        if temp.next is None:
            self.head = None
            return
        while temp.next.next:
            temp = temp.next
        temp.next = None

LL = linkedList()
while True:
    print("Linked List")
    print("1. To insert at begin\n2. To display the list\n3. To insert at end\n4. To create a list\n5. To Delete begin\n6. To Delete end\n0. To exit\n")
    var = int(input("Enter your choice: "))
    if var == 1:
        data = int(input("Enter the element: "))
        LL.insertBegin(data)
    elif var == 2:
        LL.display()
    elif var == 3:
        data = int(input("Enter the element: "))
        LL.insertEnd(data)
    elif var == 4:
        LL.createList()
    elif var == 5:
        LL.deleteBegin()
    elif var == 6:
        LL.deleteEnd()
    elif var == 0:
        exit()
    else:
        print("Wrong input")