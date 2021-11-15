%{

#include    <stdio.h>
enum Token_T{
	tok_ID=256,		 // 标识符
	tok_INTEGER,	 // 整数
	tok_INT,		 // int
	tok_VOID,		 // void
	tok_CONST,		 // const
	tok_IF,			 // if
	tok_ELSE,		 // else
	tok_WHILE,		 // while
	tok_BREAK,		 // break
	tok_CONTINUE,	 // continue
	tok_RETURN,		 // return
	tok_ADD,		 // +
	tok_SUB,		 // -
	tok_MUL,		 // *
	tok_DIV,		 // /
	tok_MODULO,		 // %
	tok_LESS,		 // <
	tok_LESSEQ,		 // <=
	tok_GREAT,		 // >
	tok_GREATEQ,	 // >=
	tok_NOTEQ,		 // !=
	tok_EQ,		 	 // ==
	tok_NOT,		 // !
	tok_AND, 		 // &&
	tok_OR,			 // ||
	tok_ASSIGN,		 // =
	tok_LPAR,		 // (
	tok_RPAR,		 // )
	tok_LBRACKET,	 // {
	tok_RBRACKET,	 // }
	tok_LSQUARE,	 // [
	tok_RSQUARE,	 // ]
	tok_COMMA,		 // ,
	tok_SEMICOLON	 // ;
};

%}

ID  ([a-zA-Z_][a-zA-Z0-9_]*)
INTEGER ([-]*[0-9]+[.]*[0-9]*)
INT (int)
VOID    (void)
CONST   (const)
IF  (if)
ELSE    (else)
WHILE   (while)
BREAK   (break)
CONTINUE    (continue)
RETURN  (return)
ADD (\+)
SUB (\-)
MUL (\*)
DIV (\/)
MODULO  (%)
LESS    (<)
LESSEQ  (<=)
GREAT   (>)
GREATEQ (>=)
NOTEQ   (!=)
EQ  (==)
NOT (!)
AND (&&)
OR  (\|\|)
ASSIGN  (=)
LPAR    (\()
RPAR    (\))
LBRACKET    (\{)
RBRACKET    (\})
LSQUARE (\[)
RSQUARE (\])
COMMA   (,)
SEMICOLON   (;)

%%

{INTEGER}  {return tok_INTEGER;}
{INT}  {return tok_INT;}
{VOID}  {return tok_VOID;}
{CONST}  {return tok_CONST;}
{IF}  {return tok_IF;}
{ELSE}  {return tok_ELSE;}
{WHILE}  {return tok_WHILE;}
{BREAK}  {return tok_BREAK;}
{CONTINUE}  {return tok_CONTINUE;}
{RETURN}  {return tok_RETURN;}
{ID}  {return tok_ID;}
{ADD}  {return tok_ADD;}
{SUB}  {return tok_SUB;}
{MUL}  {return tok_MUL;}
{DIV}  {return tok_DIV;}
{MODULO}  {return tok_MODULO;}
{LESS}  {return tok_LESS;}
{LESSEQ}  {return tok_LESSEQ;}
{GREAT}  {return tok_GREAT;}
{GREATEQ}  {return tok_GREATEQ;}
{NOTEQ}  {return tok_NOTEQ;}
{EQ}  {return tok_EQ;}
{NOT}  {return tok_NOT;}
{AND}  {return tok_AND;}
{OR}  {return tok_OR;}
{ASSIGN}  {return tok_ASSIGN;}
{LPAR}  {return tok_LPAR;}
{RPAR}  {return tok_RPAR;}
{LBRACKET}  {return tok_LBRACKET;}
{RBRACKET}  {return tok_RBRACKET;}
{LSQUARE}  {return tok_LSQUARE;}
{RSQUARE}  {return tok_RSQUARE;}
{COMMA}  {return tok_COMMA;}
{SEMICOLON}  {return tok_SEMICOLON;}
[ \t] {}

%%

int main(){
    int flag = 0;
    while (flag = yylex()){
        switch(flag){
            case tok_ID:
                printf("%d %s\n", flag, yytext);
                continue;
            case tok_INTEGER:
                printf("%d %s\n", flag, yytext);
                continue;
            default:
                printf("%d\n", flag);
                continue;
        }
    }
    return 0;
}
