def sum_mul_operation(nums: list[int], key: int) -> int:
	result = nums[0]
	for num in nums[1:]:
		if key & 1:
			result *= num
		else:
			result += num
		key >>= 1
	return result

def get_input_lines() -> list[str]:
	with open('../input.txt', 'r') as f:
		return f.readlines()

def part1(input_lines: list[str]) -> int:
	result = 0
	for i, line in enumerate(input_lines):
		x, ys = line.split(':')

		x = int(x)
		ys = tuple(int(y) for y in ys.split())
		
		min_operation = 0
		max_operation = int(2 ** (len(ys) - 1))

		for op in range(min_operation, max_operation):
			if (x == sum_mul_operation(ys, op)):
				result += x
				break
	
	return result

def is_possible_ternary(x: int, ys: list[int], leading_x: int = 0) -> bool:
	if len(ys) == 0:
		return x == leading_x
	
	first_y = ys[0]
	rest_ys = ys[1:]

	return (is_possible_ternary(x, rest_ys, leading_x + first_y) or
		is_possible_ternary(x, rest_ys, leading_x * first_y) or
		is_possible_ternary(x, rest_ys, int(str(leading_x) + str(first_y))))

def part2(input_lines: list[str]) -> int:
	result = 0
	for i, line in enumerate(input_lines):
		x, ys = line.split(':')

		x = int(x)
		ys = tuple(int(y) for y in ys.split())
		
		if is_possible_ternary(x, ys):
			result += x
	
	return result

def main() -> None:
	input_lines = get_input_lines()
	
	print(f'Part1: {part1(input_lines)}')
	print(f'Part2: {part2(input_lines)}')

if __name__ == '__main__':
	main()