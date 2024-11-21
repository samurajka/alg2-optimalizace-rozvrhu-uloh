NAME=main
OBJFILES=main.o Task.o TaskSolver.o

CC=g++
CFLAGS= 

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

all: $(NAME)

dep:
	$(CC) -MM *.cpp >dep.list

-include dep.list

$(NAME): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $@