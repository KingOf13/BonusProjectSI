all: poly clean

student_code: student_code.o tests.o
	@gcc -o student_code student_code.o tests.o -lcunit
	@./student_code

student_code.o: student_code.c student_code.h
	@gcc -c student_code.c -o student_code.o

student_code.o: tests.c student_code.h
	@gcc -c tests.c -lcunit -o tests.o

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf student_code
