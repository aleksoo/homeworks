#!/usr/bin/env python3

if __name__=="__main__":
    plik = open("test.txt","w+")
    plik.write("asd1\n")
    plik.write("elo\n")
    
    plik.mode = 'r'
    for line in plik
        print(plik[line])

    plik.close

