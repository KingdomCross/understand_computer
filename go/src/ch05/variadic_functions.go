package main

import (
	"fmt"
	"os"
)

// 可变参数函数定义
func sum(vals ...int) int {
	total := 0
	for _, val := range vals {
		total += val
	}
	return total
}

func ps_max(vals []int) (int, int) {
	flag := 0
	re := ^(int(^uint(0) >> 1))
	// fmt.Printf("%d\n", re)
	if vals == nil {
		return 0, flag
	} else {
		flag = 1
		for _, val := range vals {
			if val > re {
				re = val
			}
		}
		
		return re, flag
	}
}

func Max(vals ...int) {
	// 注意vals的类型为 []int 
	// fmt.Printf("%T\n", vals)
	max, flag := ps_max(vals)
	if flag == 0 {
		fmt.Printf("No input data\n")
	} else {
		fmt.Printf("Max value: %d\n", max)
	}
}

func f(...int) {}
func g([]int)  {}

// 注意用法， interface表示函数最后一个参数可以接受任意类型
func errorf(linenum int, format string, args ...interface{}) {
	fmt.Fprintf(os.Stderr, "Line %d: ", linenum)
	fmt.Fprintf(os.Stderr, format, args...)
	fmt.Fprintln(os.Stderr)
}

func main() {
	fmt.Println(sum())
	fmt.Println(sum(1, 2, 3, 4))
	fmt.Println(sum(1, 2, 3, 4, 5, 6, 7))

	values := []int{1, 2, 3, 4, 8}
	fmt.Println(sum(values...))

	// 注意输出区别
	fmt.Printf("%T\n", f)
	fmt.Printf("%T\n", g)

	//
	linenum, name := 12, "count"
	errorf(linenum, "undefined: %s", name)

	Max()
	Max(1, 2, 3, 4)
	Max(values...)

}
