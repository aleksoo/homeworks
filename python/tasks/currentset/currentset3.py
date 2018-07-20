import sys
sys.path.insert(0, '../lib')

# https://www.crummy.com/software/BeautifulSoup/bs4/doc/
from bs4 import BeautifulSoup as BS

def parse(fobj):
    '''
    Parse HTML file and extract targets data
    '''

    root = BS(fobj, 'html.parser')
    tbllst = root.find_all('table')

    lista=[]


    for table in tbllst:
        for tbody in table:
            if tbody.name:
                for tr in tbody:
                    # iterating over children might look as follows:
                    # for td in tr:
                    #    print(td.text)
                    # !!!Your code here!!!
                    lista2=[]
                    for i, col in enumerate(tr):
                        if (i == 0 or i == 2 or i == 9):
                            lista2.append(col.text)
                    
                    lista.append(list(reversed(lista2)))
    return lista


def report(targets):
    '''
    Generate targets report to standard output in the form:
    <HW type>

    <Target name> <Target IP>
    <Target name> <Target IP>
    ...
    <Target name> <Target IP>

    <HW type>

    <Target name> <Target IP>
    <Target name> <Target IP>
    ...
    <Target name> <Target IP>
    ...

    '''

    # !!!Your code here!!!
    #targets[0] = ['HW type', 'Target IP', 'description']
    #print(len(targets[2]))

    dictionary={}



    for target in targets[1:]:
        type1=target[0] # w target na [0] jest nazwa hwtype
        if type1 not in dictionary: #sprawdzamy czy juz jest nazwa hwtype w slowniku
            dictionary[type1]=[] # tworzymy key o wartosci hwtype z lista
        dictionary[type1].append(target) #wrzucamy do tego keya cale
        
    keys = list(dictionary.keys())
    keys.sort()

    for key in keys:
        print(key)
        dictionary[key].sort(key=lambda a: a[2])
        for value in dictionary[key]:
            print(value[2]+' '+value[1])
        print()
 

             
        


def main():
    with open('currentsets.html') as f:
        report(parse(f))


if __name__ == '__main__':
    main()


