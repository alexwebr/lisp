CC=clang
CFLAGS=-pedantic -Werror -Wall -Wextra -std=c99

lexer_driver: lexer.o lexer_driver.o

parser_driver: lexer.o stack.o parser.o parser_driver.o

clean:
	rm -f *.o *_driver *_driver_output

tests: lexer_driver parser_driver
	# Test lexer
	./lexer_driver < lexer_input > lexer_driver_output
	diff lexer_driver_output lexer_output
	rm lexer_driver_output
	# Test parser
	./parser_driver < parser_input > parser_driver_output
	diff parser_driver_output parser_output
	rm parser_driver_output
