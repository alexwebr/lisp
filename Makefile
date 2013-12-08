lexer_driver: lex.o lexer_driver.o

clean:
	rm -f *.o *_driver *_driver_output

test: lexer_driver
	./lexer_driver < lexer_input > lexer_driver_output
	diff lexer_driver_output lexer_output
