def main() -> None:
    liste:list = [1, 2, 3, 4, 5]
    l = []
    for i in range(len(liste)):
        l.append(liste[i] * liste[i])
    print(l)

    summe = sum(liste)
    
    max = 0

    for i in range(len(liste)):
        if liste[i] > max:
            max = liste[i]
        else: 
            continue
    print(max)

    min = 0
    for i in range(len(liste)):
        if liste[i] < min:
            min = liste[i]
        else:
            continue
    print(min)

if __name__ == "__main__":
    main()