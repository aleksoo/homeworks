
class Temperature(object):
    '''
    Wrapper for temperature in Fahrenheit scale

    Input values should be given in Celsius and converted using formula:
    Celsius * 1.8 + 32

    >>> t = Temperature(30)
    >>> t.temperature
    86.0
    >>> t.temperature = 35
    >>> t.temperature
    95.0
    '''
    def __init__(self, celsius):
        self.temperature = celsius

