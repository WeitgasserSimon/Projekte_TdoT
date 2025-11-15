'''
File: Hy02_input.py
Author: Weitgasser Simon
Date: 2024-19-02
Brief: inputs
'''

def main() -> None:
    formatierte_wertzuweisungen()

def basicinput() -> None:
    try: 
        x =  input("x = ")
        print(x, type(x))
    except:
        print("ihre eingabe war keine ganzzahl")

def formatierte_wertzuweisungen(): 
    a  = 1_000_000_000
    print(f'{a=:_}')
    b:int = int(1e9)    #typecast mit int(), ! typehint ist keine Deklaration !
    print(b, type(b), id(b)) # id für die adresse

if __name__ =='__main__': 
    main()