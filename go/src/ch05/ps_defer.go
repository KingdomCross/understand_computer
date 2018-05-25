package main

import (
	"fmt"
	"log"
	"time"
)

// 注意观察log输出顺序
func bigSlowOperation() {
	defer trace("bigSlowOperation")() // don't forget the extra parentheses
	// ...lots of work...
	log.Printf("in bigSlowOperation()")
	time.Sleep(1 * time.Second) // simulate slow operation by sleeping
}

func trace(msg string) func() {
	start := time.Now()
	log.Printf("enter %s", msg)
	return func() {
		log.Printf("exit %s (%s)", msg, time.Since(start))
	}
}

// 注意观察最后的值，defer在return之后执行
func double(x int) int {
	return x + x
}
func ps_double(x int) (result int) {
	defer func() { fmt.Printf("double(%d) = %d\n", x, result) }()
	return x + x
}

// 注意观察函数执行
func triple(x int) (result int) {
	defer func() { result += x }()
	return ps_double(x)
}

func main() {
	bigSlowOperation()
	fmt.Println(ps_double(4))
	fmt.Println(triple(4))
}
