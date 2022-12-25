package main

import (
	"fmt"
	"math"
)

func main() {
	var a, b, c float64
	fmt.Scan(&a, &b, &c)

	var i, j, k float64
	fmt.Scan(&i, &j, &k)

	times := math.Min(math.Min(a/i, b/j), c/k)

	fmt.Print(a-i*times, b-j*times, c-k*times)
}
