from collections import defaultdict
import math

def get_input_lines() -> list[str]:
    with open('../input.txt') as f:
        return f.read().splitlines()

def integer_normal(point: tuple[int, int]) -> tuple[int, int]:
    x, y = point
    if x == 0:
        return (0, y // abs(y))
    if y == 0:
        return (x // abs(x), 0)
    gcd = abs(math.gcd(x, y))
    return (x // gcd, y // gcd)

def part1(input_lines: list[str]) -> int:
    width = len(input_lines[0])
    height = len(input_lines)

    positions = defaultdict(list)
    for x in range(0, width):
        for y in range(0, height):
            if input_lines[y][x] != '.':
                positions[input_lines[y][x]].append((x, y))

    antinodes = set()
    for _, position in positions.items():
        for i in range(0, len(position)):
            for j in range(i + 1, len(position)):
                x1, y1 = position[i]
                x2, y2 = position[j]
                
                x3 = x1 + x1 - x2
                y3 = y1 + y1 - y2

                if 0 <= x3 < width and 0 <= y3 < height:
                    antinodes.add((x3, y3))

                x4 = x2 + x2 - x1
                y4 = y2 + y2 - y1

                if 0 <= x4 < width and 0 <= y4 < height:
                    antinodes.add((x4, y4))

    return len(antinodes)

def part2(input_lines: list[str]) -> int:
    width = len(input_lines[0])
    height = len(input_lines)

    positions = defaultdict(list)
    for x in range(0, width):
        for y in range(0, height):
            if input_lines[y][x] != '.':
                positions[input_lines[y][x]].append((x, y))

    antinodes = set()
    for _, position in positions.items():
        for i in range(0, len(position)):
            for j in range(i + 1, len(position)):
                x1, y1 = position[i]
                x2, y2 = position[j]

                dx1 = x1 - x2
                dy1 = y1 - y2
                dx2 = x2 - x1
                dy2 = y2 - y1

                dx1, dy1 = integer_normal((dx1, dy1))
                dx2, dy2 = integer_normal((dx2, dy2))
                
                x3, y3 = x1, y1
                while 0 <= x3 < width and 0 <= y3 < height:
                    antinodes.add((x3, y3))
                    if input_lines[y3][x3] == '.':
                        input_lines[y3] = input_lines[y3][:x3] + '#' + input_lines[y3][x3 + 1:]
                    x3 += dx2
                    y3 += dy2

                while 0 <= x1 + dx1 < width and 0 <= y1 + dy1 < height:
                    x1 += dx1
                    y1 += dy1
                    antinodes.add((x1, y1))
                    if input_lines[y1][x1] == '.':
                        input_lines[y1] = input_lines[y1][:x1] + '#' + input_lines[y1][x1 + 1:]

                while 0 <= x2 + dx2 < width and 0 <= y2 + dy2 < height:
                    x2 += dx2
                    y2 += dy2
                    antinodes.add((x2, y2))
                    if input_lines[y2][x2] == '.':
                        input_lines[y2] = input_lines[y2][:x2] + '#' + input_lines[y2][x2 + 1:]
                        
    print('\n'.join(input_lines))
    return len(antinodes)

def main():
	input_lines = get_input_lines()
	
	print(f'Part1: {part1(input_lines)}')
	print(f'Part2: {part2(input_lines)}')

if __name__ == '__main__':
    main()