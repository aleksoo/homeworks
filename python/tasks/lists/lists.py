
def first_last(words):
    '''
    Given a list of strings, return the count of the number of
    strings where the string length is 2 or more and the first
    and last chars of the string are the same.
    '''
    i=0
    for x in words:
      if ((len(x) >= 2) and (x[0]==x[-1])):
        i+=1
    return i

def last(a):
    '''
    Extract the last element from a tuple -- used for custom sorting below.
    '''
    # !!!Your code here!!!



def sort_key(tuples):
    '''
    Given a list of non-empty tuples, return a list sorted in increasing
    order by the last element in each tuple.
    e.g. [(1, 7), (1, 3), (3, 4, 5), (2, 2)] yields
    [(2, 2), (1, 3), (3, 4, 5), (1, 7)]
    Hint: use a custom key= function to extract the last element form each tuple.
    '''
    # !!!Your code here!!!

    lista=()
    lista = sorted(tuples, key=lambda tuples: tuples[1])
    return lista

    #return lista


# Simple provided test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def test(got, expected):
  if got == expected:
    prefix = ' OK '
  else:
    prefix = '  X '
  print ('%s got: %s expected: %s' % (prefix, repr(got), repr(expected)))


# Calls the above functions with interesting inputs.
def main():
  print ('first_last')
  test(first_last(['aba', 'xyz', 'aa', 'x', 'bbb']), 3)
  test(first_last(['', 'x', 'xy', 'xyx', 'xx']), 2)
  test(first_last(['aaa', 'be', 'abc', 'hello']), 1)

  print
  print ('sort_key')
  test(sort_key([(1, 3), (3, 2), (2, 1)]), [(2, 1), (3, 2), (1, 3)])
  test(sort_key([(2, 3), (1, 2), (3, 1)]), [(3, 1), (1, 2), (2, 3)])
  test(sort_key([(1, 7), (1, 3), (3, 4, 5), (2, 2)]),
       [(2, 2), (1, 3), (3, 4, 5), (1, 7)])


if __name__ == '__main__':
  main()
