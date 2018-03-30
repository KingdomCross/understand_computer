D_SRC=../src
D_INC=-I ../include/
D_OBJ=.
TATGET=./main

SRC_C= $(foreach dir, $(D_SRC), $(wildcard $(dir)/*.c))  
OBJ_C= $(addprefix $(D_OBJ)/,$(patsubst %.c,%.o,$(notdir $(SRC_C))))	  

# $(warning  $(SRC_C))
# $(warning  $(OBJ_C))

$(TATGET):$(OBJ_C)
	gcc -o $@ $^ -lm

$(D_OBJ)/%.o:$(D_SRC)/%.c
	gcc  -Wall $(D_INC) -c -o $@ $^

.PHONY: clean
clean:
	rm -f $(D_OBJ)/*.o $(TATGET)
