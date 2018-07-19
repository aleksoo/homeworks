
def currentset(f):
    r'''
    Read currentsets csv file and make iterator
    that returns Currentset objects
    
    >>> from StringIO import StringIO
    >>> f = StringIO('Faraday;10.121.85.21;HPOMS-01\n')
    >>> list(currentset(f))
    [Currentset(name="Faraday",ip="10.121.85.21",desc="HPOMS-01")]
    '''
    buff = f.read()
    while buff:
        yield buff
        buff = f.read()


def main():
    with open('currentsets.csv') as f:
        for cs in currentset(f):
            print (cs)

if __name__ == '__main__':
    main()
