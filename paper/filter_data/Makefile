obj=point_num_with_C_N.o
point_num_with_C_N:$(obj)
	g++ -o point_num_with_C_N $(obj)
point_num_with_C_N.o:point_num_with_C_N.cpp
	g++ -c point_num_with_C_N.cpp

.PHONY:clean
clean:
	-rm  point_num_with_C_N  $(obj)
