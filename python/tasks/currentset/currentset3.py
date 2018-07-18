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

    for table in tbllst:
        for tbody in table:
            if tbody.name:
                for tr in tbody:
                    # iterating over children might look as follows:
                    # for td in tr:
                    #    print(td.text)
                    # !!!Your code here!!!


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


def main():
    with open('currentsets.html') as f:
        report(parse(f))


if __name__ == '__main__':
    main()


