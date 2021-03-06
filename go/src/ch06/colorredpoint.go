package main

import (
	"fmt"
	"image/color"
	"log"
	"math"
)

type Point struct{ X, Y float64 }

type ColorredPoint struct {
	Point
	Color color.RGBA
}

type ps_ColorredPoint struct {
	*Point
	Color color.RGBA
}

// as a method of the Point type
func (p Point) Distance(q Point) float64 {
	return math.Hypot(q.X-p.X, q.Y-p.Y)
}

func (p *Point) ScaleBy(factor float64) {
	p.X *= factor
	p.Y *= factor
}

func main() {
	ps_test001()
	ps_test002()
	ps_test003()
}

// ps_test001()
func ps_test001() {
	log.Println("ps_test001()")
	var cp ColorredPoint
	cp.X = 1
	fmt.Println(cp.Point.X)
	cp.Point.Y = 2
	fmt.Println(cp.Y)
}

// ps_test002()
func ps_test002() {
	log.Println("ps_test002()")
	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	var p = ColorredPoint{Point{1, 2}, red}
	var q = ColorredPoint{Point{5, 4}, blue}

	fmt.Println(p.Distance(q.Point))
	p.ScaleBy(2)
	q.ScaleBy(2)
	fmt.Println(p.Distance(q.Point))
}

// ps_test003()
func ps_test003() {
	log.Println("ps_test003()")
	red := color.RGBA{255, 0, 0, 255}
	blue := color.RGBA{0, 0, 255, 255}
	p := ps_ColorredPoint{&Point{1, 2}, red}
	q := ps_ColorredPoint{&Point{5, 4}, blue}

	fmt.Println(p.Distance(*q.Point))
	q.Point = p.Point
	q.ScaleBy(2)
	fmt.Println(*p.Point, *q.Point)
}
