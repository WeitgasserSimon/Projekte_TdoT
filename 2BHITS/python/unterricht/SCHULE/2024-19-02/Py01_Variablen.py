'''
File: Py01_Variablen.py
Author: Weitgasser Simon
Date: 2024-19-02
Brief: Varibalen und Datentypen
'''

def variablen_und_datentypen() -> None:
    deklaration_und_initialisierung()
    deklaration_mit_typehints()
    gleichtzeitige_zuweisung()


def deklaration_und_initialisierung() -> None:
    print('\n Deklaration und Initialisierung:')
    print('--------------------------:')
    a = -4
    b = 2.718
    c = 'jai hat eine große Lanze'
    d = "er mag es sehr gerne"
    e = "er liebt \"es\""
    f = True 
    print(a,b)
    print(c)
    print(d)
    print(e)

def deklaration_mit_typehints() -> None:
    print('\n Deklaration mit Typehints:')
    print('--------------------------:')
    a:int = 7
    b:float = 3.14159265358979323846
    c:str = 'danke jai'
    d:bool = False
    print(a, type(a))
    print(b, type(b))
    print(c, type(c))
    print(d, type(d))



def gleichtzeitige_zuweisung() -> None:
    print('\n Deklaration mit Typehints:')
    print('--------------------------:')
    a, b = -4, 7
    a, b = b, a

if __name__ == '__main__': 
    variablen_und_datentypen()