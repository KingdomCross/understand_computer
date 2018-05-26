package main

import (
	"fmt"
)

type Point struct{ X, Y float64 }

func (p Point) Add(q Point) Point {
	return Point{p.X + q.X, p.Y + q.Y}
}

func (p Point) Sub(q Point) Point {
	return Point{p.X - q.X, p.Y - q.Y}
}

type Path []Point

func (path Path) TranslateBy(offset Point, add bool) {
	var op func(p, q Point) Point
	if add {
		op = Point.Add
	} else {
		op = Point.Sub
	}

	for i := range path {
		// call either path[i].Add(offset) or path[i].Sub(offset)
		path[i] = op(path[i], offset)
	}
}

func main() {
	path := Path{Point{1, 2}, Point{2, 3}, Point{4, 5}, Point{6, 7}}
	var flag bool = false

	path.TranslateBy(Point{1, 2}, flag)
	fmt.Println(path)
}
