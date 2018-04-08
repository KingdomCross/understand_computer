obj=grid_main.o grid.o
grid_main:$(obj)
	g++ -o grid_main $(obj)
grid.o:grid.cpp grid.h
	g++ -c grid.cpp

.PHONY:clean
clean:
	-rm  grid_main  $(obj)
