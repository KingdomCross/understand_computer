package main

import (
	"fmt"
	"time"
)

type Employee struct {
	ID        int
	Name      string
	Address   string
	DoB       time.Time
	Position  string
	Salary    int
	ManagerID int
}

func EmployeeByID(id int) *Employee {
	var temp *Employee
	return temp
}

func main() {
	var dilbert Employee

	dilbert.Salary = 5000

	position := &dilbert.Position
	*position = "Senior " + *position

	var employeeOfTheMonth *Employee = &dilbert
	// attend to the pointer to access value
	employeeOfTheMonth.Position += " (proactive team player)"
	// the previous line equal to the follow line
	(*employeeOfTheMonth).Position += " (proactive team player)"

	fmt.Println(*position)
	fmt.Println(employeeOfTheMonth.Position)
	fmt.Println((*employeeOfTheMonth).Position)

	/*
		fmt.Println(EmployeeByID(dilbert.ManagerID).Position)

		id := dilbert.ID
		EmployeeByID(id).Salary = 0
	*/
}
