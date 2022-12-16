package main

import "fmt"

func cond_swap(a *int64, b *int64) {
	if *b < *a {
		tmp := *a
		*a = *b
		*b = tmp
	}
}

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var a, b, c int64
		fmt.Scan(&a, &b, &c)

		cond_swap(&a, &b)
		cond_swap(&b, &c)

		fmt.Printf("Scenario #%d:\n", i+1)
		if a*a+b*b == c*c {
			fmt.Printf("yes\n\n")
		} else {
			fmt.Printf("no\n\n")
		}
	}
}
