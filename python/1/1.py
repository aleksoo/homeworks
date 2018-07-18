#!/usr/bin/env python3
def is_palindrome(word):
    if word == word[::-1]: 
        return True
    else: 
        return False

if __name__=='__main__':
    word1='ela'
    palindrome = is_palindrome(word1)
    print(palindrome)