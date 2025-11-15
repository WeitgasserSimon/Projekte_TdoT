def count_words(text: str) -> int:
    return len(text.split())

def countwords(text) -> int:
    counter: int = 0
    c: str
    for c in text:
        if c == " ":
            counter += 1
        else: 
            continue
    if counter >= 1:
        counter += 1

    return counter

class tier:
    def __init__(self) -> None:
        self._sound = "n/a"
    def __str__(self) -> str:
        return f"{self._sound}"

    def makesound(self) -> None:
        print(f"{self._sound}")

class katze(tier):
    def __init__(self) -> None:
        super().__init__()
        self._sound = "miau"

class hund(tier):
    def __init__(self) -> None:
        super().__init__()
        self._sound = "wau"

    

if __name__ == "__main__":
    text = "ufo361 ist der beste deutschrapper der welt!"
    print(count_words(text))

    katze1 = katze()
    katze1.makesound()

    hund1 = hund()
    hund1.makesound()

    tier1 = tier()
    tier1.makesound()