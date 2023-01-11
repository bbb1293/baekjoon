package main

import "fmt"

func solve(a int, nums ...int) int {
	ret := 0

	for _, num := range nums {
		if a < num {
			ret += a
		} else {
			ret += num
		}
	}

	return ret
}

func main() {
	var n, a, b, c int
	fmt.Scan(&n, &a, &b, &c)

	fmt.Println(solve(n, a, b, c))
}
