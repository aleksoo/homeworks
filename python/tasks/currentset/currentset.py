import sys
sys.path.insert(0, '../lib')

# Wrapper for ElementTree
# api: http://docs.python.org/2/library/xml.etree.elementtree.html
import ElementSoup as ES


def parse(fobj):
    '''
    Parse HTML file and extract targets data
    '''

    root = ES.parse(fobj)
    tbllst = root.findall('.//table')
    dictionary={}
    lister=[dictionary]
    for elem in tbllst[0][0]:  # iterating over table/tbody/tr elements
        if elem.tag == 'tr':
            # elem is 'tr' tag with a few children 'td'
            # iterating over children might look as follows:
            # for td in elem:
            #    print td.text
            # !!!Your code here!!!


            if elem.tag =='/tr':
                break

    return lister


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


