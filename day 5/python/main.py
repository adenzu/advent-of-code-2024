import sys
from collections import defaultdict

def part1(first_section: list[str], second_section: list[str]) -> int:
    def to_pair_tuple(s: str) -> tuple[int, int]:
        return tuple(map(int, s.split('|')[::-1]))
    
    requires = defaultdict(set)

    for page1, page2 in map(to_pair_tuple, first_section):
        requires[page1].add(page2)

    def to_int_list(s: str) -> list[int]:
        return [int(n) for n in s.split(',')]

    def correctly_ordered(pages: list[int]) -> bool:
        for index, page1 in enumerate(pages):
            for page2 in pages[index + 1:]:
                if page2 in requires[page1]:
                    return False
        return True

    result = 0
    for pages in map(to_int_list, second_section):
        if correctly_ordered(pages):
            result += pages[len(pages) // 2]

    return result

def part2(first_section: list[str], second_section: list[str]) -> int:
    def to_pair_tuple(s: str) -> tuple[int, int]:
        return tuple(map(int, s.split('|')[::-1]))
    
    requires = defaultdict(set)

    for page1, page2 in map(to_pair_tuple, first_section):
        requires[page1].add(page2)

    def to_int_list(s: str) -> list[int]:
        return [int(n) for n in s.split(',')]

    def correctly_ordered(pages: list[int]) -> bool:
        for index, page1 in enumerate(pages):
            for page2 in pages[index + 1:]:
                if page2 in requires[page1]:
                    return False
        return True

    def fixed(pages: list[int]) -> list[int]:
        values = defaultdict(int)
        for i, page1 in enumerate(pages):
            for page2 in pages[:i]:
                if page2 in requires[page1]:
                    values[page1] += 1
            for page2 in pages[i + 1:]:
                if page2 in requires[page1]:
                    values[page1] += 1
        return sorted(pages, key=lambda x: values[x])

    result = 0
    for pages in map(to_int_list, second_section):
        if not correctly_ordered(pages):
            result += fixed(pages)[len(pages) // 2]

    return result

def load_input() -> tuple[list[str], list[str]]:
    with open("../input.txt") as f:
        data = f.read().splitlines()
    
    section_separation_index = data.index("")

    return (data[:section_separation_index], data[section_separation_index + 1:])

def main():
    first_section, second_section = load_input()

    if len(sys.argv) == 1:
        print("Part 1:", part1(first_section, second_section))
        print("Part 2:", part2(first_section, second_section))
    elif len(sys.argv) == 2:
        if sys.argv[1] == "1":
            print("Part 1:", part1(first_section, second_section))
        elif sys.argv[1] == "2":
            print("Part 2:", part2(first_section, second_section))
        else:
            print("Invalid argument. Please pass 1 or 2.")

if __name__ == "__main__":
    main()