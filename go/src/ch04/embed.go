package main

import (
	"fmt"
)

type Point struct {
	X, Y int
}

type Circle struct {
	Center Point
	Radius int
}

type Wheel struct {
	Circle Circle
	Spokes int
}

type Ps_Circle struct {
	Point
	Radius int
}

type Ps_Wheel struct {
	Ps_Circle
	Spokes int
}

func main() {
	var w Wheel
	w.Circle.Center.X = 8
	w.Circle.Center.Y = 8
	w.Circle.Radius = 5
	w.Spokes = 20

	var ps_w Ps_Wheel
	ps_w.X = 8
	ps_w.Y = 8
	ps_w.Radius = 5
	ps_w.Spokes = 20

	fmt.Println(w.Circle.Center.X, ps_w.X)

	/* error init
	w = Wheel{8, 8, 5, 20}
	w = Wheel{X: 8, Y: 8, Radius: 5, Spokes: 20}

	ps_w = Ps_Wheel{8, 8, 5, 20}
	ps_w = Ps_Wheel{X: 8, Y: 8, Radius: 5, Spokes: 20}
	*/

	w = Wheel{Circle{Point{8, 8}, 5}, 20}
	ps_w = Ps_Wheel{Ps_Circle{Point{8, 8}, 5}, 20}
	
	ps_w = Ps_Wheel{
		Ps_Circle: Ps_Circle{
			Point:  Point{X: 8, Y: 8},
			Radius: 5,
		},
		Spokes: 20, // NOTE: trailing comma necessary here (and at Radius)
	}
	
	fmt.Printf("%#v\n", w)
	fmt.Printf("%#v\n", ps_w)
	
	ps_w.X = 42	
	fmt.Printf("%#v\n", ps_w)

}
