import random
from typing import Optional

class Solution:
    def __init__(self, head: Optional[ListNode]):
        self.arr = []
        temp = head
        while temp != None:
            self.arr.append(temp.val)
            temp = temp.next

    def getRandom(self) -> int:
        return random.choice(self.arr)


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()