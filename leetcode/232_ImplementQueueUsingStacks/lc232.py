class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack1 = []
        self.stack2 = []
        #self.size1 = len(self.stack1)
        #self.size2 = len(self.stack2)


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        while self.stack2:
            self.stack1.append(self.stack2.pop())
        self.stack1.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if not self.stack1 and not self.stack2:
            return None
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        return self.stack2.pop()


    def peek(self) -> int:
        """
        Get the front element.
        """
        if not self.stack1 and not self.stack2:
            return None
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        return self.stack2[-1]


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        if not self.stack1 and not self.stack2:
            return True
        else:
            return False



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
