class MyIterable(object):
    def __init__(self):
        self.first = []
        self.i = 0
    def __iter__(self):
        return self
    def __next__(self):
        if self.i < len(self.first):
            item = self.first[self.i]
            self.i += 1
            return item
        raise StopIteration
    def add(self, s):
        self.first.append(s)

if __name__=="__main__":
    A = MyIterable()
    A.add(3)
    A.add(2)
    A.add(7)
    A.add(9)
    A.add(0)
    for i in A:
        print(i)