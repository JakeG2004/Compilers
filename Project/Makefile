.PHONY: build clean tokenizer

build: tokenizer

tokenizer:
	cd Tokenizer
	flex tokenizer.l
	g++ lex.yy.c -o a.out

clean:
	rm -f Tokenizer/lex.yy.c Tokenizer/a.out