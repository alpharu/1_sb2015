; comentário
SECTION TEXT ; comentario para teste
		INPUT		B
		INPUT		H
		LOAD		B
		MULT		H
		DIV		DOIS
		STORE		R
		OUTPUT	R
		STOP

SECTION DATA
	B:		SPACE
	H:		SPACE
	R:		SPACE
	DOIS:	CONST		2
