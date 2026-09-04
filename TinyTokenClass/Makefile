CXX = g++
CXXFLAGS = -IHelpers -Ibuild

all: a.out
build: a.out
test: 
	rm out.txt
	cat test.tc | ./a.out > out.txt

a.out: build/parser.tab.o build/lex.yy.o build/tokenizer.o build/tokenclass.o
	$(CXX) $^ -o $@

# Generate parser files in build/
build/parser.tab.c build/parser.tab.h: Parser/parser.y
	mkdir -p build
	bison -d Parser/parser.y -o build/parser.tab.c

# Generate lexer files in build/
build/lex.yy.c: Lexer/lexer.l build/parser.tab.h
	mkdir -p build
	flex -o build/lex.yy.c Lexer/lexer.l

# Compile all object files into the build/ directory
build/parser.tab.o: build/parser.tab.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/lex.yy.o: build/lex.yy.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/tokenizer.o: Helpers/tokenizer.cpp Helpers/tokenizer.h Helpers/tokenclass.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/tokenclass.o: Helpers/tokenclass.cpp Helpers/tokenclass.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build a.out