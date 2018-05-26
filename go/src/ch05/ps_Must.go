package main

import (
	"fmt"
)

func main() {
	Mustf(3)
}


// Must前缀表示调用者不能接收不合法输入
func Mustf(x int) {
	fmt.Printf("f(%d) \n", x+0/x) // panics if x == 0
	defer fmt.Printf("defer %d\n", x)
	Mustf(x - 1)
}
