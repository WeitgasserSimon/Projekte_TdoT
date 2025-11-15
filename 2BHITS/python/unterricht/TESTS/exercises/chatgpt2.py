'''
File:   komplexitaet.py
Author: Susanne Meerwald-Stadler
Date:   2024-05-13
Brief:  komplexitaet: wörter in liste zählen. Basierend auf Abgaben von bsp.py
'''

import timeit

l:list = []

def words_orig() -> int:
    d:dict = {}

    for w in l:
        if w in d:
            d[w] += 1
        else:
            d[w] = 1

    return len(d)

# like jber
def words_keys() -> int:
    d:dict = {}

    for w in l:
        # added .keys()
        if w in d.keys():
            d[w] += 1
        else:
            d[w] = 1

    return len(d)


# like blib
def words_count() -> int:
    d:dict = {}

    for w in l:
        # use .count(), simple but slow
        d[w] = l.count(w)

    return len(d)

# like fisg, geoj
def words_range() -> int:
    d:dict = {}

    for w in l:
        counter = 0
        # even slower, go over list and compare each element with w
        for i in range(len(l)):#n
            if w == l[i]:
                counter = counter + 1
        d[w] = counter

    return len(d)


if __name__ == '__main__':
    for i in range(0, 10000): 
        l.append(f'{i % 433}')

    # number is repetitions
    print('orig', timeit.timeit('words_orig()', setup= 'from __main__ import words_orig', number=10))

    print('keys', timeit.timeit(words_keys, number=10))

    # so slow, reduce repetitions
    print('count', timeit.timeit(words_count, number=3))

    print('range', timeit.timeit(words_range, number=3))