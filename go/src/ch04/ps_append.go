package main

import (
	"fmt"
)

// append 
func ps_append() {
	var runes []rune
	for _, r := range "hello, 世界" {
		runes = append(runes, r)
	}
	runes = append(runes, 'p', 's')
	fmt.Printf("%q\n", runes)

}

// simulate append
func appendInt(x []int, y int) []int {
	var z []int
	zlen := len(x) + 1
	if zlen <= cap(x) {
		// there is room to grow. Extend the slice
		z = x[:zlen]
	} else {
		// there is insufficient space. Allocate a new array.
		// Grow by doubling, for amortized linear complexity
		zcap := zlen
		if zcap < 2*len(x) {
			zcap = 2 *len(x)
		}
		z = make([]int, zlen, zcap)
		copy(z,x) // a built-in function; see text
	}
	z[len(x)] = y
	return z
}

func main() {
	ps_append()
	
	//
	var x, y []int 
	for i := 0; i < 10; i++ {
		y = appendInt(x, i)
		fmt.Printf("%d cap = %d\t%v\n", i, cap(y), y)
		x = y
	}
	
}
