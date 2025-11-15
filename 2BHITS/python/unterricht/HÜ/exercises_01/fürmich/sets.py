def main() -> None:
    aufgabe1()
    aufgabe2()
    aufgabe3()
    aufgabe4()
    aufgabe5()
    aufgabe6()
    aufgabe7()
    aufgabe8()
    aufgabe9()
    aufgabe10()

def aufgabe1() -> None:
    def have_common_elements(set1, set2):
        return len(set1.intersection(set2)) > 0

    set1 = {1, 2, 3}
    set2 = {3, 4, 5}
    print(f"Aufgabe 1: {have_common_elements(set1, set2)}")

def aufgabe2() -> None:
    def common_elements(tuple1, tuple2):
        return tuple(set(tuple1).intersection(set(tuple2)))

    tuple1 = (1, 2, 3, 4)
    tuple2 = (3, 4, 5, 6)
    print(f"Aufgabe 2: {common_elements(tuple1, tuple2)}")

def aufgabe3() -> None:
    from itertools import chain, combinations

    def all_subsets(s):
        return list(chain.from_iterable(combinations(s, r) for r in range(len(s)+1)))

    my_set = {1, 2, 3}
    print(f"Aufgabe 3: {all_subsets(my_set)}")

def aufgabe4() -> None:
    def remove_duplicates_from_tuple(input_tuple):
        return tuple(set(input_tuple))

    my_tuple = (1, 2, 3, 2, 4, 3)
    print(f"Aufgabe 4: {remove_duplicates_from_tuple(my_tuple)}")

def aufgabe5() -> None:
    def tuples_to_dictionary(list_of_tuples):
        result_dict = {}
        for tpl in list_of_tuples:
            key = tpl[0]
            value = tpl[1]
            if key in result_dict:
                result_dict[key].append(value)
            else:
                result_dict[key] = [value]
        return result_dict

    my_list = [(1, 'a'), (2, 'b'), (1, 'c')]
    print(f"Aufgabe 5: {tuples_to_dictionary(my_list)}")

def aufgabe6() -> None:
    def intersection_of_tuples(tuple1, tuple2):
        return tuple(set(tuple1).intersection(set(tuple2)))

    tuple1 = (1, 2, 3, 4)
    tuple2 = (3, 4, 5, 6)
    print(f"Aufgabe 6: {intersection_of_tuples(tuple1, tuple2)}")

def aufgabe7() -> None:
    def symmetric_difference(set1, set2):
        return set1.symmetric_difference(set2)

    set1 = {1, 2, 3}
    set2 = {3, 4, 5}
    print(f"Aufgabe 7: {symmetric_difference(set1, set2)}")

def aufgabe8() -> None:
    def is_subset(subset, superset):
        return set(subset).issubset(set(superset))

    tuple1 = (1, 2)
    tuple2 = (1, 2, 3, 4)
    print(f"Aufgabe 8: {is_subset(tuple1, tuple2)}")

def aufgabe9() -> None:
    def cartesian_product(set1, set2):
        return {(x, y) for x in set1 for y in set2}

    set1 = {1, 2}
    set2 = {'a', 'b'}
    print(f"Aufgabe 9: {cartesian_product(set1, set2)}")

def aufgabe10() -> None:
    def count_occurrences(input_tuple, element):
        return input_tuple.count(element)

    my_tuple = (1, 2, 2, 3, 4, 2)
    element_to_count = 2
    print(f"Aufgabe 10: {count_occurrences(my_tuple, element_to_count)}")

if __name__ == "__main__":
    main()
