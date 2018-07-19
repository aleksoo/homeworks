
class Currentset(object):
    '''
    Create Currentset class with attributes: name, ip, description
    It should work like this:

    >>> cs = Currentset(*('Faraday;10.121.85.21;HPOMS-01'.split(';')))
    >>> cs
    name=Faraday,ip=10.121.85.21,description=HPOMS-01
    >>> [cs]
    [name=Faraday,ip=10.121.85.21,description=HPOMS-01]
    >>> print cs
    name=Faraday,ip=10.121.85.21,description=HPOMS-01
    '''
    def __init__(self, name, ip, desc):
        self.info = name+' '+ip+' '+desc
        self.i = 0
    def __str__(self):
        return str(self.info)
    

def main():
    cs = Currentset(*('Faraday;10.121.85.21;HPOMS-01'.split(';')))
    cs

if __name__=="__main__":
    main()

