lexer_driver: lex.o lexer_driver.o

parser_driver: lex.o stack.o parse.o parser_driver.o

clean:
	rm -f *.o *_driver *_driver_output

test: lexer_driver parser_driver
	./lexer_driver < lexer_input > lexer_driver_output
	diff lexer_driver_output lexer_output
	./parser_driver < parser_input > parser_driver_output
	diff parser_driver_output parser_output
