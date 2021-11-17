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

int advance()
{
    token = yylex();
    printf("token: %s %d\n", yytext, token);
}

void myerror()
{
    fprintf(stderr, "Panic!!!\n");
}

int ConstExp() {}

int LOrExp() {}

int LAndExp() {}

int EqExp() {}

int RelExp() {}

int AddExp() {}

int MulExp() {}

int UnaryOp() {}

int FuncRParams() {}

int UnaryExp() {}

int Number() {}

int PrimaryExp() {}

int LOrExp() {}

int AddExp() {}

int Cond() {}

int Exp() {}

int LVal() {}

int Stmt()
{
    if (LVal())
    {
        if (token == tok_ASSIGN)
        {
            advance();
            if (Exp())
            {
                if (token == tok_SEMICOLON)
                {
                    advance();
                    return 1;
                }
            }
        }
        myerror();
        return -1;
    }

    if (Exp())
    {
        if (token == tok_SEMICOLON)
        {
            advance();
            return 1;
        }
        myerror();
        return -1;
    }
    else
    {
        if (token == tok_SEMICOLON)
        {
            advance();
            return 1;
        }
    }

    if (Block())
    {
        return 1;
    }

    if (token == tok_IF)
    {
        advance();
        if (token == tok_LPAR)
        {
            advance();
            if (Cond())
            {
                if (token == tok_RPAR)
                {
                    advance();
                    if (Stmt())
                    {
                        if (token == tok_ELSE)
                        {
                            advance();
                            if (Stmt())
                            {
                                return 1;
                            }
                            else
                            {
                                myerror();
                                return -1;
                            }
                        }
                        return 1;
                    }
                }
            }
        }
    }

    if (token == tok_WHILE)
    {
        advance();
        if (token == tok_LPAR)
        {
            advance();
            if (Cond())
            {
                if (token == tok_RPAR)
                {
                    advance();
                    if (Stmt())
                    {
                        return 1;
                    }
                }
            }
        }
        myerror();
        return -1;
    }

    if (token == tok_BREAK)
    {
        advance();
        if (token == tok_SEMICOLON)
        {
            return 1;
        }
        myerror();
        return -1;
    }

    if (token == tok_CONTINUE)
    {
        advance();
        if (token == tok_SEMICOLON)
        {
            return 1;
        }
        myerror();
        return -1;
    }

    if (token == tok_RETURN)
    {
        advance();
        Exp();
        if (token == tok_SEMICOLON)
        {
            return 1;
        }
        myerror();
        return -1;
    }

    myerror();
    return -1;
}

int BlockItem()
{
    if (Decl() || Stmt())
    {
        return 1;
    }
    myerror();
    return -1;
}

int Block()
{
    if (token == tok_LBRACKET)
    {
        advance();
        while (BlockItem())
        {
            continue;
        }
        if (token == tok_RBRACKET)
        {
            advance();
            return 1;
        }
    }
    myerror();
    return -1;
}

int FuncFParam()
{
    if (BType())
    {
        if (token == tok_ID)
        {
            advance();
            if (token == tok_LSQUARE)
            {
                advance();
                if (token == tok_RSQUARE)
                {
                    advance();
                    while (token == tok_LSQUARE)
                    {
                        advance();
                        if (Exp())
                        {
                            if (token == tok_RSQUARE)
                            {
                                advance();
                                continue;
                            }
                        }
                        myerror();
                        return -1;
                    }
                }
            }
        }
    }
    myerror();
    return -1;
}

int FuncFParams()
{
    if (FuncFParam)
    {
        while (token == tok_COMMA)
        {
            advance();
            if (FuncFParam)
            {
                continue;
            }
            myerror();
            return -1;
        }
    }
    myerror();
    return -1;
}

int FuncType()
{
    if (token == tok_VOID)
    {
        return 1;
    }
    else if (token == tok_INT)
    {
        return 1;
    }
    myerror();
    return -1;
}

int InitVal()
{
    if (Exp())
    {
        advance();
        return 1;
    }
    if (token == tok_LBRACKET)
    {
        advance();
        if (InitVal())
        {
            while (token == tok_COMMA)
            {
                advance();
                InitVal();
            }
        }
        if (token == tok_RBRACKET)
        {
            advance();
            return 1;
        }
    }
    return -1;
}

int VarDef()
{
    if (token == tok_ID)
    {
        advance();
        while (token == tok_LSQUARE)
        {
            advance();
            ConstExp();
            if (token == tok_RSQUARE)
            {
                advance();
            }
            else
            {
                myerror();
                break;
            }
        }
        if (token == tok_ASSIGN)
        {
            advance();
            InitVal();
            return 1;
        }
        return 1;
    }
    myerror();
    return -1;
}

int VarDecl()
{
    if (BType())
    {
        if (VarDef())
        {
            while (token == tok_COMMA)
            {
                advance();
                if (VarDef())
                {
                    continue;
                }
                myerror();
                return -1;
            }
            if (token == tok_SEMICOLON)
            {
                myerror();
                return 1;
            }
        }
    }
    myerror();
    return -1;
}

int ConstInitVal()
{
    if (ConstExp())
    {
        return 1;
    }
    if (token == tok_LBRACKET)
    {
        advance();
        if (ConstInitVal())
        {
            while (token == tok_COMMA)
            {
                advance();
                if (ConstInitVal())
                {
                    continue;
                }
                myerror();
                return -1;
            }
        }
        if (token == tok_RSQUARE)
        {
            advance();
            return 1;
        }
    }
    myerror();
    return -1;
}

int ConstExp()
{
    if (AddExp())
    {
        return 1;
    }
    return -1;
}

int ConstDef()
{
    if (token == tok_ID)
    {
        advance();
    }
    while (token == tok_LSQUARE)
    {
        advance();
        if (ConstExp())
        {
            if (token == tok_RSQUARE)
            {
                advance();
                continue;
            }
            myerror();
            return -1;
        }
        else
        {
            myerror();
            return -1;
        }
    }
    if (token == tok_ASSIGN)
    {
        advance();
        ConstInitVal();
        return 1;
    }
    myerror();
    return -1;
}

int BType()
{
    if (token == tok_INT)
    {
        advance();
        return 1;
    }
    myerror();
    return -1;
}

int VarDecl()
{
    BType();
    VarDef();
    while (token == tok_COMMA)
    {
        advance();
        VarDef();
    }
    if (token == tok_SEMICOLON)
    {
        advance();
        CompUnit();
        // CompUnit
        return 1;
    }
    else
    {
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int ConstDecl()
{
    if (token == tok_CONST)
    {
        BType();
        ConstDef();
        while (token == tok_COMMA)
        {
            advance();
            if (ConstDef())
            {
                continue;
            }
            myerror();
            return -1;
        }
        if (token == tok_SEMICOLON)
        {
            advance();
            CompUnit();
            // CompUnit
            return 1;
        }
    }
    myerror();
    return -1;
}

int FuncDef()
{
    FuncType();
    if (token == tok_ID)
    {
        advance();
        if (token == tok_LPAR)
        {
            advance();
            FuncFParams();
            if (token == tok_RPAR)
            {
                advance();
                if (Block())
                {
                    return -1;
                }
            }
        }
    }
    myerror();
    return -1;
}

int Decl()
{
    if (ConstDef() || VarDecl())
    {
        return 1;
    }
    myerror();
    return -1;
}

int CompUnit()
{
    CompUnit();
    if (Decl() || FuncDef())
    {
        return 1;
    }
    return -1;
}

int main(int argc, char **argv)
{
    while (1)
    {
        advance();
        int r = CompUnit();
    }
}
