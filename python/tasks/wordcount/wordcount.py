import sys

def file_parser(fname):
    words={}
    plik = open(fname, 'r')
    buffer = plik.read().split()
    
    plik.close()
    for word in buffer:
        if word in words:
            words[word]+=1
        else: 
            words[word]=1
    return words

def print_count(fname):
    '''
    Prints one per line '<word> <count>' sorted by word for the given file
    '''
    # !!!Your code here!!!
    words = file_parser(fname)            

    for slowo in [(k, words[k]) for k in words]:
        print(slowo)

def print_top(fname):
    '''
    Prints the top count listing for the given file
    '''
    # !!!Your code here!!!
    words = file_parser(fname)
        
    posortowane=[(k, words[k]) for k in sorted(words, key=words.get, reverse=True)]
    for slowo in range(0, 20):
        print(posortowane[slowo])
      

def main():
    if len(sys.argv) != 3:
        print ('Usage: ./wordcount.py {--count | --top} <file name>')
        sys.exit(1)

    option = sys.argv[1]
    filename = sys.argv[2]
    if option == '--count':
        print_count(filename)
    elif option == '--top':
        print_top(filename)
    else:
        print ('unknown option: ') + option
        sys.exit(1)


if __name__ == '__main__':
    main()
