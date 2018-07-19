def deprecated(f):
    '''This is a decorator which can be used to mark functions
    as deprecated. It will result in a warning being emitted
    when the function is used.

    >>> @deprecated
    ... def some_old_function(x, y):
    ...     return x + y
    ... 
    >>> some_old_function(1, 2)
    Call to deprecated function <some_old_function>.
    3
    '''


