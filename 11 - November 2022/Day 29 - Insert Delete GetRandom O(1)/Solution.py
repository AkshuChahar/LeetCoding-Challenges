class RandomizedSet:

    def __init__(self):
        # Initialise a dictionary and a list to store the values and the indexes.
        self.ele = {}
        self.ind = []

    def insert(self, val: int) -> bool:
        # Check if the given value is already present.
        if val in self.ele:
            return False
        self.ele[val] = len(self.ind)
        self.ind.append(val)
        return True

    def remove(self, val: int) -> bool:
        # Check if the given value is present.
        if val in self.ele:
            last = self.ind[-1]
            pos = self.ele[val]
            # Update the values.
            self.ele[last] = pos
            self.ind[pos] = last
            self.ele.pop(val)
            self.ind.pop()
            return True
        return False

    def getRandom(self) -> int:
        return random.choice(self.ind)


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()