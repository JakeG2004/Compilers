CXX = g++
CXXFLAGS = -IHelpers -Ibuild

TESTDIR    = Tests
OUTDIR     = Outputs
RESULTSDIR = results
PACKAGEDIR = package

# Every Tests/foo.c- is expected to have a matching Outputs/foo.out
TESTSRCS = $(wildcard $(TESTDIR)/*.c-)

all: c-
build: c-

# Run every test, print PASS/FAIL for each, and a summary at the end.
test: c-
	@mkdir -p $(RESULTSDIR)
	@pass=0; fail=0; skip=0; total=0; \
	for f in $(TESTSRCS); do \
		name=$$(basename "$$f" .c-); \
		expected="$(OUTDIR)/$$name.out"; \
		actual="$(RESULTSDIR)/$$name.out"; \
		total=$$((total+1)); \
		if [ ! -f "$$expected" ]; then \
			echo "SKIP  $$name  (no $$expected)"; \
			skip=$$((skip+1)); \
			continue; \
		fi; \
		./c- < "$$f" > "$$actual" 2>&1; \
		if diff -q "$$actual" "$$expected" > /dev/null 2>&1; then \
			echo "PASS  $$name"; \
			pass=$$((pass+1)); \
		else \
			echo "FAIL  $$name"; \
			fail=$$((fail+1)); \
		fi; \
	done; \
	echo "------------------------------------"; \
	echo "$$pass passed, $$fail failed, $$skip skipped ($$total total)"

# Run a single test by name and show the diff, e.g. `make test-one NAME=chars`
test-one: c-
	@mkdir -p $(RESULTSDIR)
	@if [ -z "$(NAME)" ]; then echo "Usage: make test-one NAME=<testname>"; exit 1; fi
	@./c- < "$(TESTDIR)/$(NAME).c-" > "$(RESULTSDIR)/$(NAME).out" 2>&1; \
	if diff -u "$(RESULTSDIR)/$(NAME).out" "$(OUTDIR)/$(NAME).out"; then \
		echo "PASS  $(NAME)"; \
	else \
		echo "FAIL  $(NAME)"; \
	fi

package:
	rm -rf $(PACKAGEDIR)
	@mkdir -p $(PACKAGEDIR)
	cp Helpers/* $(PACKAGEDIR)
	cp Parser/parser.y $(PACKAGEDIR)
	cp Lexer/lexer.l $(PACKAGEDIR)
	cp package_makefile $(PACKAGEDIR)/Makefile
	tar -cf submission.tar -C package .

c-: build/parser.tab.o build/lex.yy.o build/tokenizer.o build/tokenclass.o build/error.o build/errorhandler.o
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

build/error.o: Helpers/error.cpp Helpers/error.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

build/errorhandler.o: Helpers/errorhandler.cpp Helpers/errorhandler.h
	mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean: pclean
	rm -rf build c- results

pclean:
	rm -rf package submission.tar

.PHONY: all build test test-one clean
