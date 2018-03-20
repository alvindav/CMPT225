all: gscheck

gscheck: gscheck.o char_stack.o
	g++ gscheck.o char_stack.o -o gscheck

gscheck.o:
	g++ -c gscheck.cpp

char_stack.o: 
	g++ -c char_stack.cpp

clean:
	rm -f *o gscheck *.gt
