PROGRAM = asteroid_field
LDFLAGS = -Wall -Wextra
LDLIBS	= -lGL -lGLU -lglut -lm 
LDDEPS	= main.o  on_timer.o on_key.o on_display.o on_reshape.o object.o


$(PROGRAM): $(LDDEPS)
	gcc $(LDFLAGS) -o $(PROGRAM) $^ $(LDLIBS)

clean:
	rm *.o

re: clean $(PROGRAM)

rebuild: re

on_timer.o: on_timer.c on_timer.h
	gcc -c -o $@ $< $(LDLIBS)


on_key.o: on_key.c on_key.h
	gcc -c -o $@ $< $(LDLIBS)

on_display.o: on_display.c on_display.h
	gcc -c -o $@ $< $(LDLIBS)

on_reshape.o: on_reshape.c on_reshape.h
	gcc -c -o $@ $< $(LDLIBS)

object.o: object.c object.h
	gcc -c -o $@ $< $(LDLIBS)