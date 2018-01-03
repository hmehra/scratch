import sys

''' BST implementation in python '''
class Node():
    def __init__(self, key = None, value = None, left = None, right = None,
                 parent = None, extra = 0):
        self.key = key
        if parent is not None:
            self.value = parent.value*2 + extra
        else:
            self.value = value
        self.left = left
        self.right = right
        self.parent = parent

    def hasLeftChild(self):
        return self.left

    def hasRightChild(self):
        return self.right

class BST():
    def __init__(self):
        self.root = None

    def _insert(self, key, value, current):
        if key < current.key:
            if current.hasLeftChild():
                self._insert(key, value, current.left)
            else:
                current.left = Node(key, value, parent = current)
        elif key > current.right:
            if current.hasRightChild():
                self._insert(key, 2*value, current.right)
            else:
                current.right = Node(key, value, parent = current, extra=1)

    def insert(self, key, value):
        if self.root:
            self._insert(key, 1, self.root)
        else:
            self.root = Node(key, 1)

    def _get(self, key, current):
        if not current:
            return None
        if current.key == key:
            return current
        elif current.key < key:
            return self._get(key, current.right)
        else:
            return self._get(key, current.left)

    def get(self, key):
        if self.root:
            res = self._get(key, self.root)
            return res if res else None
        else:
            return None

    def levelOrderTraversal(self):
        queue = []
        ans = []
        count = 1
        queue.append(self.root)
        ans.append(count)
        while len(queue) > 0:
            node = queue.pop(0)
            if node is not None:
                if node.hasLeftChild():
                    count += 1
                    queue.append(node.left)
                    ans.append(count)
                else:
                    count += 1
                    queue.append(None)
                    ans.append(0)

                if node.hasRightChild():
                    count += 1
                    queue.append(node.right)
                    ans.append(count)
                else:
                    queue.append(None)
                    count += 1
                    ans.append(0)

            else:
                count += 2

        string = ""
        for item in ans:
            if item != 0:
                string += str(item) + " "
        print string

myBST = BST()
num = int(raw_input())
nodes = []
for line in sys.stdin:
    nodes.append(line.split(" "))

for item in nodes:
    myBST.insert(int(item), 0)

ans = ""
for item in nodes:
    node = myBST.get(int(item))
    if node is not None:
        ans += str(node.value) + " "
print ans
