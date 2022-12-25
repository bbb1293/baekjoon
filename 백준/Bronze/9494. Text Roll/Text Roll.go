package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	for true {
		scanner.Scan()
		n, _ := strconv.Atoi(scanner.Text())

		if n == 0 {
			break
		}

		ret := 1

		for i := 0; i < n; i++ {
			scanner.Scan()
			s := scanner.Text()

			if ret <= len(s) {
				update := false
				for j := ret - 1; j < len(s); j++ {
					if s[j] == ' ' {
						ret = j + 1
						update = true
						break
					}
				}

				if !update {
					ret = len(s) + 1
				}
			}
		}
		fmt.Println(ret)
	}
}
