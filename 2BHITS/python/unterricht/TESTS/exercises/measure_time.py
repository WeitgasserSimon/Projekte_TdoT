import timeit

def test():
    return sum(range(100))

# Messen der Ausführungszeit von test() 1000-mal
print(timeit.timeit(test, number=1000))

if __name__ == "__main__":
    result = test()
    print(result)
