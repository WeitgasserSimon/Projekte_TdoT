'''
File:    lzk02.py
Author:
Date:
Brief:   4.3.2024 lzk
'''

def squaredEven(liste:list) -> list:
    # squared = liste
    # print(id(liste))
    # print(id(squared))
    squared = [x**2 for x in liste if x % 2 == 0]
    squared.sort()
    return squared

def main() -> None:
    print(squaredEven([3,8,12,5,6,10,7]))

if __name__ == '__main__':
    main()
