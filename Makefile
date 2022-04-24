all: org__borium__javarecompiler__Recompiler.o
	echo Done with 'all'.

clean:
	echo Not cleaning anything

org__borium__javarecompiler__Recompiler.o: org__borium__javarecompiler__Recompiler.cpp org__borium__javarecompiler__Recompiler.h
	echo compiling $<
	g++ -c $< -o $@
