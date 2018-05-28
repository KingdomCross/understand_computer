package sort

type Interface interface {
	Len() int
	Less(i, j int) bool // x, j are indices of sequence elements
	Swap(i, j int) 
}

/*
	其他数据类型使用sort.Sort(pama)时，
	只需要定义里面的三个函数, 如stringsort.go所示
*/
