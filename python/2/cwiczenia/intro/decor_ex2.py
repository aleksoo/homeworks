
def timeit(f):
    '''This is a decorator which can be used to measure
    function execution time.

    >>> @timeit
    ... def f():
    ...     time.sleep(2)
    ... 
    >>> f()
    Time: 2.00
    '''
