


class LinkedListNode:
    def __init__(self, key=-1, val=-1):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.head = LinkedListNode()
        self.tail = LinkedListNode()
        self.head.next = self.tail
        self.tail.prev = self.head 

        self.cache = dict()
        self.capacity = capacity
        self.size = 0

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        else:
            node = self.cache[key]
            res = node.val
            self.moveToHead(node)
            return res

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            node.val = value
            self.moveToHead(node)
        else:
            node = LinkedListNode(key, value)
            self.addHead(node)
            self.cache[key] = node
            self.size += 1
            if self.size > self.capacity:
                delkey = self.tail.prev.key
                self.delNode(self.tail.prev)
                print(self.cache.keys, delkey)
                self.cache.pop(delkey)
                self.size -= 1

    def addHead(self, node):
        node.prev = self.head
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node

    def delNode(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        return node

    def moveToHead(self, node):
        dnode = self.delNode(node)
        self.addHead(dnode)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)