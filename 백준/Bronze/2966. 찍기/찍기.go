package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	var s string
	fmt.Scan(&s)

	abc := [3]string{"ABC", "BABC", "CCAABB"}
	cnt := [3]int{0}
	name := [3]string{"Adrian", "Bruno", "Goran"}

	for i := 0; i < 3; i++ {
		for j := 0; j < n; j++ {
			if s[j] == abc[i][j%len(abc[i])] {
				cnt[i]++
			}
		}
	}

	ret := cnt[0]
	for i := 1; i < 3; i++ {
		if ret < cnt[i] {
			ret = cnt[i]
		}
	}

	fmt.Println(ret)
	for i := 0; i < 3; i++ {
		if cnt[i] == ret {
			fmt.Println(name[i])
		}
	}
}
