#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum yytokentype
{
    tok_ID = 256, // 标识符
    tok_INTEGER,  // 整数
    tok_INT,      // int
    tok_VOID,     // void
    tok_CONST,    // const
    tok_IF,       // if
    tok_ELSE,     // else
    tok_WHILE,    // while
    tok_BREAK,    // break
    tok_CONTINUE, // continue
    tok_RETURN,   // return
    tok_ADD,      // +
    tok_SUB,      // -
    tok_MUL,      // *
    tok_DIV,      // /
    tok_MODULO,   // %
    tok_LESS,     // <
    tok_LESSEQ,   // <=
    tok_GREAT,    // >
    tok_GREATEQ,  // >=
    tok_NOTEQ,    // !=
    tok_EQ,       // ==
    tok_NOT,      // !
    tok_AND,      // &&
    tok_OR,       // ||
    tok_ASSIGN,   // =
    tok_LPAR,     // (
    tok_RPAR,     // )
    tok_LBRACKET, // {
    tok_RBRACKET, // }
    tok_LSQUARE,  // [
    tok_RSQUARE,  // ]
    tok_COMMA,    // ,
    tok_SEMICOLON // ;
};

extern int yylex();
extern int yylval;
extern char *yytext;
extern FILE *yyin;

int token;

// void error()
// {
//     printf("error!!!");
//     return -1;
// }

int advance()
{
    token = yylex();
    printf("token: %s %d\n", yytext, token);
}

int program()
{
    if (token == tok_INT)
    {
        advance();
        declList();
    }
    else if (token == tok_CONST)
    {
        advance();
        declConst();
    }
}

int declList()
{
    if (token == tok_ID)
    {
        advance();
        if (token == tok_SEMICOLON)
        {
            advance();
            program();
        }
        else if (token == tok_COMMA)
        {
            advance();
            declList();
        }
        else if (token == tok_ASSIGN)
        {
            // advance();
            // integer();
            expr();
        }
        else if (token == tok_LPAR)
        {
            advance();
            funcDecl();
        }
        else if (token == tok_LSQUARE)
        {
            advance();
            declArr();
        }
    }
}

// int integer()
// {
//     if (token == tok_INTEGER)
//     {
//         advance();
//         if (token == tok_SEMICOLON)
//         {
//             advance();
//         }
//         else if (token == tok_COMMA)
//         {
//             advance();
//             declList();
//         }
//     }
// }

int declArr()
{
    if (token == tok_INTEGER)
    {
        advance();
        if (token == tok_RSQUARE)
        {
            advance();
            declArrList();
        }
    }
}

int declArrList()
{
    if (token == tok_LSQUARE)
    {
        advance();
        declArr();
    }
    else if (token == tok_ASSIGN)
    {
        expr();
    }
    else if (token == tok_SEMICOLON)
    {
        advance();
        program();
    }
    else if (token == tok_COMMA)
    {
        advance();
        if (token == tok_LSQUARE)
        {
            advance();
            declArr();
        }
    }
}

int declConst()
{
    if (token == tok_INT)
    {
        advance();
        if (token == tok_ID)
        {
            advance();
            if (token == tok_ASSIGN)
            {
                stmt();
                // TODO : 多定义
            }
            else if (token == tok_LSQUARE)
            {
                advance();
                declConstArr();
            }
        }
    }
}

int declConstArr()
{
    if (token == tok_INTEGER)
    {
        advance();
        if (token == tok_RSQUARE)
        {
            advance();
            declConstArrList();
        }
    }
}
int declConstArrList()
{
    if (token == tok_SEMICOLON)
    {
        advance();
        program();
    }
    else if (token == tok_COMMA)
    {
        advance();
        declConstArr();
    }
}

int funcDecl()
{
    parm();
}

int parm()
{
    if (token == tok_INT)
    {
        advance();
        parmList();
    }
}

int parmList()
{
    if (token == tok_ID)
    {
        advance();
        if (token == tok_COMMA)
        {
            advance();
            parm();
        }
        else if (token == tok_LSQUARE)
        {
            advance();
            if (token == tok_RSQUARE)
            {
                advance();
                if (token == tok_COMMA)
                {
                    advance();
                    parm();
                }
                else if (token == tok_RPAR)
                {
                    advance();
                    stmt();
                }
            }
        }
    }
}

int stmt() {}

int expr() {}

int main(int argc, char **argv)
{
    while (1)
    {
        advance();
        int r = program();
    }
}
