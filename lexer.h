/*
	Copyright (c) 2010 Noel R. Cower

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgment in the product documentation would be
	appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.

	3. This notice may not be removed or altered from any source
	distribution.
*/

#ifndef LEXER_H_BICMCZIT
#define LEXER_H_BICMCZIT

// Comment/remove this to disable support for the additional tokens
// (see README.md/Additions for details)
#define BMAX_USE_ADDITIONS

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	TOK_INVALID=0,

	TOK_ID,

	TOK_END_KW,

	TOK_FUNCTION_KW,
	TOK_ENDFUNCTION_KW,

	TOK_METHOD_KW,
	TOK_ENDMETHOD_KW,

	TOK_TYPE_KW,
	TOK_EXTENDS_KW,
	TOK_ABSTRACT_KW,
	TOK_FINAL_KW,
	TOK_NODEBUG_KW,
	TOK_ENDTYPE_KW,

	TOK_EXTERN_KW,
	TOK_ENDEXTERN_KW,

	TOK_REM_KW,
	TOK_ENDREM_KW,

	TOK_FLOAT_KW,
	TOK_DOUBLE_KW,
	TOK_BYTE_KW,
	TOK_SHORT_KW,
	TOK_INT_KW,
	TOK_LONG_KW,
	TOK_STRING_KW,
	TOK_OBJECT_KW,

	TOK_LOCAL_KW,
	TOK_GLOBAL_KW,
	TOK_CONST_KW,

	TOK_VARPTR_KW,
	TOK_PTR_KW,
	TOK_VAR_KW,

	TOK_NULL_KW,

	TOK_STRICT_KW,
	TOK_SUPERSTRICT_KW,

	TOK_FRAMEWORK_KW,

	TOK_MODULE_KW,
	TOK_MODULEINFO_KW,

	TOK_IMPORT_KW,
	TOK_INCLUDE_KW,

	TOK_PRIVATE_KW,
	TOK_PUBLIC_KW,

	TOK_OR_KW,
	TOK_AND_KW,
	TOK_SHR_KW,
	TOK_SHL_KW,
	TOK_SAR_KW,
	TOK_MOD_KW,
	TOK_NOT_KW,

	TOK_WHILE_KW,
	TOK_WEND_KW,
	TOK_ENDWHILE_KW,

	TOK_FOR_KW,
	TOK_NEXT_KW,
	TOK_UNTIL_KW,
	TOK_TO_KW,
	TOK_EACHIN_KW,

	TOK_REPEAT_KW,
	TOK_FOREVER_KW,

	TOK_IF_KW,
	TOK_ENDIF_KW,
	TOK_ELSE_KW,
	TOK_ELSEIF_KW,
	TOK_THEN_KW,

	TOK_SELECT_KW,
	TOK_CASE_KW,
	TOK_DEFAULT_KW,
	TOK_ENDSELECT_KW,

	TOK_SELF_KW,
	TOK_SUPER_KW,
	TOK_PI_KW,
	TOK_NEW_KW,

	// extensions
	TOK_PROTOCOL_KW,
	TOK_ENDPROTOCOL_KW,
	TOK_AUTO_KW,
	TOK_IMPLEMENTS_KW,

	TOK_COLON,
	TOK_QUESTION,
	TOK_BANG,
	TOK_HASH,
	TOK_DOT,
	TOK_DOUBLEDOT,
	TOK_TRIPLEDOT,
	TOK_AT,
	TOK_DOUBLEAT,
	TOK_DOLLAR,
	TOK_PERCENT,
	TOK_SINGLEQUOTE,
	TOK_OPENPAREN,
	TOK_CLOSEPAREN,
	TOK_OPENBRACKET,
	TOK_CLOSEBRACKET,
	TOK_OPENCURL,
	TOK_CLOSECURL,
	TOK_GREATERTHAN,
	TOK_LESSTHAN,
	TOK_EQUALS,
	TOK_MINUS,
	TOK_PLUS,
	TOK_ASTERISK,
	TOK_CARET,
	TOK_TILDE,
	TOK_GRAVE,
	TOK_BACKSLASH,
	TOK_SLASH,
	TOK_COMMA,
	TOK_SEMICOLON,
	TOK_PIPE,
	TOK_AMPERSAND,
	TOK_NEWLINE,

	TOK_ASSIGN_ADD,
	TOK_ASSIGN_SUBTRACT,
	TOK_ASSIGN_DIVIDE,
	TOK_ASSIGN_MULTIPLY,
	TOK_ASSIGN_POWER,

	TOK_ASSIGN_SHL,
	TOK_ASSIGN_SHR,
	TOK_ASSIGN_SAR,
	TOK_ASSIGN_MOD,

	TOK_ASSIGN_XOR,
	TOK_ASSIGN_AND,
	TOK_ASSIGN_OR,

	TOK_ASSIGN_AUTO,
	TOK_DOUBLEMINUS,
	TOK_DOUBLEPLUS,

	TOK_NUMBER_LIT,
	TOK_HEX_LIT,
	TOK_BIN_LIT,
	TOK_STRING_LIT,

	TOK_LINE_COMMENT,
	TOK_BLOCK_COMMENT,
	
	TOK_EOF,
	
	TOK_LAST=TOK_EOF,
	TOK_COUNT
} token_kind_t;


typedef struct s_token {
	token_kind_t kind;
	const char *from, *to;
	int line, column;
} token_t;

typedef struct s_lexer lexer_t;

/* allocates a new lexer for the range specified by source_begin and source_end and returns it */
lexer_t *lexer_new(const char *source_begin, const char *source_end);
/* destroys the contents (tokens and such) of the lexer and releases its memory */
void lexer_destroy(lexer_t *lexer);
/* runs the lexer - you should only do this once, doing it twice will result in the entire list of tokens being duplicated for no reason */
int lexer_run(lexer_t *lexer);
/* returns the error string or NULL if there is no error */
const char *lexer_get_error(lexer_t *lexer);
/* returns the number of tokens identified by the lexer */
int lexer_get_num_tokens(lexer_t *lexer);
/* returns the kind of the token at the index and copies that token to the provided token if it isn't null */
token_kind_t lexer_get_token(lexer_t *lexer, int index, token_t *token);
/* returns a copy of all tokens identified by the lexer; number of tokens is copied to num_tokens */
token_t *lexer_copy_tokens(lexer_t *lexer, int *num_tokens);
/* returns a copy of the string contents of the token, must be freed via free(str) */
char *token_to_string(const token_t* tok);


#ifdef __cplusplus
}
#endif

#endif /* end of include guard: LEXER_H_BICMCZIT */
