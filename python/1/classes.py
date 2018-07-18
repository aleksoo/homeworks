#!/usr/bin/env python3

class KlasaA():
    def __init__(self):
        print("Konstruktor A, a=1")
        self._a=1
    def SetA(self, x):
        self._a=x
    def PrintA(self):
        print(self._a)

class KlasaB(KlasaA):
    def __init__(self):
        print("Konstruktor B")
        self._a=5
        self._b=0
    def SetB(self, x):
        self._b=x
    def PrintB(self):
        print(self._b)
        
class KlasaC(KlasaA):
    def SetA(self):
        print("Zasloniecie")

if __name__=="__main__":
    A = KlasaA()
    A.SetA(10)
    A.PrintA()
    A.SetA(9)
    A.PrintA()
    
    B = KlasaB()
    B.SetA(4)
    B.SetB(3)
    B.PrintA()
    B.PrintB()
    A.PrintA()

    C = KlasaC()
    C.SetA()