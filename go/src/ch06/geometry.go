package main

import (
	"fmt"
	"log"
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

func (p *Point) ScaleBy(factor float64) {
	p.X *= factor
	p.Y *= factor
}

func main() {
	ps_receiver_test001()
	ps_receiver_test002()
	ps_receiver_test003()
}

// Test 001
func ps_receiver_test001() {
	log.Printf("ps_receiver_test001")

	p := Point{1, 2}
	q := Point{3, 4}

	fmt.Println(Distance(p, q))
	fmt.Println(p.Distance(q))
}

// Test 002
func ps_receiver_test002() {
	log.Printf("ps_receiver_test002")

	perim := Path{
		{1, 1},
		{5, 1},
		{5, 4},
		{1, 1},
	}
	fmt.Println(perim.Distance())
}

// Test 003
func ps_receiver_test003() {
	log.Printf("ps_receiver_test003")
	// method 1
	r := &Point{1, 2}
	r.ScaleBy(2)
	fmt.Println(*r)

	// method 2
	p := Point{1, 2}
	pptr := &p
	pptr.ScaleBy(2)
	fmt.Println(p)

	// method 3
	p3 := Point{1, 2}
	(&p3).ScaleBy(2)
	fmt.Println(p3)
}
