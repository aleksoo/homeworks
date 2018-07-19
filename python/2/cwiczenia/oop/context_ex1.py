
'''
This does not work:

import urllib2
with urllib2.urlopen('http://www.python.org/') as conn:
    print len(conn.read())

Prepare class which will make such construction possible.
It should work like this:

with <Your class>('http://www.python.org/') as conn:
    print len(conn.read())

Connection should be closed after `with` statement    
'''
