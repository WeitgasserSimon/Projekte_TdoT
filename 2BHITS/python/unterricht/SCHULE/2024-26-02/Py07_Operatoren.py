'''
File:   Py07_Operatoren.py
Author: Weitgasser Simon
Date:   2024-02-26
Brief:  Operatoren
'''

import math

def operatoren() -> None:
    arithmetische_operatoren()
    vergleichende_operatoren()
    ungefaehrer_vergleich()
    logische_operatoren()
    bitweise_operatoren()
    bitshifting()

def arithmetische_operatoren() -> None:
    a:int = 123
    b:int = 45
    print(f"{a} + {b} = {a+b}")
    print(f"{a} - {b} = {a-b}")
    print(f"{a} * {b} = {a*b}")
    print(f"{a} / {b} = {a/b}")
    print(f"{a} **{b} = {a**b}")
    print(f"{a} %{b} = {a%b}")
    print(f"{a} //{b} = {a//b}")
    
def vergleichende_operatoren() -> None:
    a = 123
    b = 45
    print(f"{a} < {b} = {a<b}")
    print(f"{a} == {b} = {a==b}")
    print(f"{a} != {b} = {a!=b}")
    x:float = 0.3
    y:float = 0.2999999999999999999999999999999999999999999999999999999
    print(f"{x} == {y} = {x==y}")

def ungefaehrer_vergleich() -> None:
    pi:float = 3.1415
    PI:float = 3.14159265358979323846 

    print(f"{pi} == {PI} = {pi==PI}")
    ergebnis:bool = math.isclose(pi, PI, rel_tol=1e-3)
    print(f"{pi} == {PI} = {ergebnis}")

def logische_operatoren() -> None:
    a:bool = True
    b:bool = False
    print(f"{a} and {b} = {a and b}")
    print(f"{a} or {b} = {a or b}")
    print(f"not {a} = {not a}")

def bitweise_operatoren() -> None:
    a:int = 0b0110
    b:int = 0b0011
    print(f"{a:04b} & {b:04b} = {a & b:}")
    print(f"{a:04b} | {b:04b} = {a | b:}")
    print(f"{a:04b} ^ {b:04b} = {a ^ b:}")
    print(f"~{a:04b} = {~a:05b}")

def bitshifting() -> None:
    a = int("0b001011", 2)
    print(f"a >> 2 = {a:06b} >> 2 = {a >> 2:06b}")
    

if __name__ == "__main__":
    operatoren()