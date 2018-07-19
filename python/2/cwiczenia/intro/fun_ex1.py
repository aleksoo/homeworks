def rgb2hex(red, green, blue):
    '''Combine RGB lights to HTML hex code

    >>> rgb2hex(112, 128, 144)
    '#708090'
    '''
    return '#%x%x%x' % (red, green, blue)

RGB = dict(red=112, green=128, blue=144)
# or
# RGB = {'red': 112, 'green': 128, 'blue': 144}

# Call `rgb2hex` function using values from `RGB` dictionary
