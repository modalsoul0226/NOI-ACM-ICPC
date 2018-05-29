FLAGS = -Wall -g

all: 3-2_Lights 3-3_Spiral_Matrix

3-2_Lights: 3-2_Lights.o
	gcc $(FLAGS) -o $@ $^

3-3_Spiral_Matrix: 3-3_Spiral_Matrix.o
	gcc $(FLAGS) -o $@ $^

%.o : %.c
	gcc -Wall -g -c $<

clean : 
	rm -f *.o 3-2_Lights 3-3_Spiral_Matrix