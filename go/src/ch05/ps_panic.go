package main

import(
	"fmt"
)

func Reset(x *int) {
	if x == nil {
		panic("x is nil") // unnecessary!
	}
}

func main() {
	var y *int  // y := new(int)
	fmt.Printf("%T\n", y)
	Reset(y)
}
