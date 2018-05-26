package main

import (
	"fmt"
	"math"
)

type Point struct{ X, Y float64 }

// A Path is a journey connecting the points with straight lines
type Path []Point

// traditional function
func Distance(p, q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

// same thing, but as a method of the Point type
func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

// Distance returns the distance traveled along the path
func (path Path) Distance() float64 {
	sum := 0.0
	for i := range path {
		if i > 0 {
			sum += path[i-1].Distance(path[i])
		}
	}
	return sum
}

func main() {
	ps_receiver_test001()
	ps_receiver_test002()
}

// Test 001
func ps_receiver_test001() {
	p := Point{1, 2}
	q := Point{3, 4}

	fmt.Println(Distance(p, q))
	fmt.Println(p.Distance(q))
}

// Test 002
func ps_receiver_test002() {
	perim := Path{
		{1, 1},
		{5, 1},
		{5, 4},
		{1, 1},
	}
	fmt.Println(perim.Distance())
}