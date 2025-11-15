global_var = 420
outer_var = 911

def main() -> None:
    printglobal()
    modify_global()
    local_var = local_scope()
    local_scope_call(local_var)
    nested_scope()
    nested_scope_call()
    modify_outer()
    shadowing_variables()
    access_global_inside_local()
    nonlocal_keyword()

def printglobal() -> None:
    print(f"{global_var}")

def modify_global() -> None:
    global global_var
    global_var = 69
    print(f"{global_var}")

def local_scope() -> int:
    local_var = 488
    return local_var

def local_scope_call(local_var: int) -> None:
    print(f"local_var={local_var}")

def nested_scope() -> None:
    inner_var = 918

def nested_scope_call() -> None:
    global outer_var
    print(f"{outer_var}")

def modify_outer() -> None:
    global outer_var
    print(f"{outer_var}")
    outer_var = 44
    print(f"{outer_var}")

def shadowing_variables() -> None:
    global g1, g2
    g1, g2 = 4, 5
    g1, g2 = 7, 8
    print(f"{g1, g2}")

def access_global_inside_local() -> None:
    global global_var, outer_var
    print(global_var)
    print(outer_var)
    outer_var = 4
    global_var = 5
    print(global_var)
    print(outer_var)

def nonlocal_keyword() -> None:
    x = 10  # Eine Variable im äußeren Funktionsbereich

    def inner_function() -> None:
        nonlocal x  # Zugriff auf die Variable aus dem äußeren Funktionsbereich
        x = 20  # Die Variable x wird im inneren Funktionsbereich geändert
        print("Innerhalb der inneren Funktion: x =", x)

    inner_function()
    print("Nach der inneren Funktion: x =", x)

if __name__ == '__main__':
    main()
