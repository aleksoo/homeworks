
class CallCounter(object):
    counter = 0
    def __init__(self, func):
        self._func = func
        

    def __call__(self, x, y, z=1):
        CallCounter.counter += 1
        return self._func(x, y, z)
    
@CallCounter
def f(x, y, z=1):
    return x+y*z


def main():  
    print(f(2, 4, 6))
    print(f(3, 5, 7))
    print(f(8, 2))
    print(CallCounter.counter)

if __name__=="__main__":
    main()