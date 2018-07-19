'''
Iterator protocol/interface requires following methods:

__iter__(self)
next(self)

'''

class Card(object):
    FACE_CARD = {11: 'J', 12: 'Q', 13: 'K'}
    
    def __init__(self, rank, suit):
        self.suit = suit
        self.rank = rank if rank <= 10 else Card.FACE_CARD[rank]

    def __str__(self):
        return "%s%s" % (self.rank, self.suit)
    

class Deck(object):
    def __init__(self):
        self.cards = [Card(7, 'S'), Card(12, 'H'), Card(4, 'D'), Card(13, 'C')]
        self.i = 0

    def __iter__(self):
        return DeckIter(self.cards)

class DeckIter(object):
    def __init__(self, seq):
        self._seq = seq
        self._current = 0

    def __next__(self):
        if self._current < len(self._seq):
            item = self._seq[self._current]
            self._current += 1
            return item
        raise StopIteration

def print_cards():
    '''
    Add to `Deck` and `DeckIter` classes missing methods, which will make
    the `Deck` object iterable and `DeckIter` object iterator,
    so this function will work without problems
    
    >>> print_cards()
    7S
    QH
    4D
    KC
    '''
    for c in Deck():
        print (c)


def main():
    print_cards()

if __name__ == '__main__':
    main()