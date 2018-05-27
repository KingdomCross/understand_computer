package main

import (
	"flag"
	"fmt"
	"time"
)

var period = flag.Duration("period", 1*time.Second, "sleep period")

func main() {
	flag.Parse()
	fmt.Printf("Sleeping for %v ... ", *period)
	time.Sleep(*period)
	fmt.Println()
}

/*  注意flag的用法

package flag

// Value is the interface to the value stored in a flag
type Value interface {
	String() string
	Set(string) error
}

*/
