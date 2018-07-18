#!/usr/bin/env python3

def foo1(it):
    lista = []
    for i in range(len(it)-1, -1, -1):
       lista.append(it[i])
    return tuple(lista)

def foo2(it):
    dicto = {}
    tup = foo1(it)
    for i in range(0, len(tup), 1):
        dicto[it[i]] = i
    return dicto


if __name__=="__main__":
    asd = [1, 3, 3, 2, 5]
    print(foo1(asd))
    print(foo2(asd))