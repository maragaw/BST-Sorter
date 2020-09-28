all: runMovies tests
runMovies: main.cpp movies.cpp movies.h utility.h
	g++ -g movies.cpp main.cpp -o runMovies
tests: tests.cpp tests.h movies.cpp movies.h utility.h
	g++ -g tests.cpp movies.cpp -o tests
clean:
	rm runMovies tests
