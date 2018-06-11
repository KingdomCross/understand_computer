package main

import (
	"errors"
	"fmt"
	"os"
	"syscall"
)

// PathError records an error and the operation and file path that caused it.
type PathError struct {
	Op   string
	Path string
	Err  error
}

func (e *PathError) Error() string {
	return e.Op + " " + e.Path + ": " + e.Err.Error()
}

var ErrNotExist = errors.New("file does not exist")

// IsNotExist returns a boolean indicating whether the error is known to
// report that a file or directory does not exist. It is satisfied by
// ErrNotExist as well as some syscall errors.
func IsNotExist(err error) bool {
	if pe, ok := err.(*PathError); ok {
		err = pe.Err
	}

	return err == syscall.ENOENT || err == ErrNotExist
}

func main() {
	_, err := os.Open("no/such/file")
	fmt.Println(os.IsNotExist(err))
}
