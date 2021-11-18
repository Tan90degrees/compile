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

int ConstExp()
{
    if (AddExp())
    {
        return 1;
    }
    myerror();
    return -1;
}

int LOrExp()
{
    if (LAndExp())
    {
        return 1;
    }
    if (LOrExp())
    {
        if (token == tok_OR)
        {
            advance();
            if (LAndExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int LAndExp()
{
    if (EqExp())
    {
        return 1;
    }
    if (LAndExp())
    {
        if (token == tok_AND)
        {
            advance();
            if (EqExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int EqExp()
{
    if (RelExp())
    {
        return 1;
    }
    if (EqExp())
    {
        if (token == tok_EQ || token == tok_NOTEQ)
        {
            advance();
            if (RelExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int RelExp()
{
    if (AddExp())
    {
        return 1;
    }
    if (RelExp())
    {
        if (token == tok_LESS || token == tok_GREAT || token == tok_LESSEQ || token == tok_GREATEQ)
        {
            advance();
            if (AddExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int AddExp()
{
    if (MulExp())
    {
        return 1;
    }
    if (AddExp())
    {
        if (token == tok_ADD || token == tok_SUB)
        {
            advance();
            if (MulExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int MulExp()
{
    if (UnaryExp())
    {
        return 1;
    }
    if (MulExp())
    {
        if (token == tok_MUL || token == tok_DIV || token == tok_MODULO)
        {
            advance();
            if (UnaryExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int UnaryOp()
{
    if (token == tok_ADD || token == tok_SUB || token == tok_NOT)
    {
        advance();
        return 1;
    }
    myerror();
    return -1;
}

int FuncRParams()
{
    if (Exp())
    {
        while (token == tok_COMMA)
        {
            advance();
            if (Exp())
            {
                continue;
            }
            myerror();
            return -1;
        }
        return 1;
    }
    myerror();
    return -1;
}

int UnaryExp()
{
    if (PrimaryExp)
    {
        return 1;
    }
    if (token == tok_ID)
    {
        advance();
        if (token == tok_LPAR)
        {
            advance();
            FuncRParams();
            if (token == tok_RPAR)
            {
                advance();
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int Number()
{
    if (token == tok_INTEGER)
    {
        advance();
        return 1;
    }
    myerror();
    return -1;
}

int PrimaryExp()
{
    if (token == tok_LPAR)
    {
        advance();
        if (Exp())
        {
            if (token == tok_RPAR)
            {
                advance();
                return 1;
            }
        }
        myerror();
        return -1;
    }
    if (LVal())
    {
        return 1;
    }
    if (Number())
    {
        return 1;
    }
    myerror();
    return -1;
}

int LOrExp()
{
    if (LAndExp())
    {
        return 1;
    }
    if (LOrExp())
    {
        if (token == tok_OR)
        {
            advance();
            if (LAndExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int AddExp()
{
    if (MulExp())
    {
        return 1;
    }
    if (AddExp())
    {
        if (token == tok_ADD || token == tok_SUB)
        {
            advance();
            if (MulExp())
            {
                return 1;
            }
        }
        myerror();
        return -1;
    }
    myerror();
    return -1;
}

int Cond()
{
    if (LOrExp())
    {
        return 1;
    }
    myerror();
    return -1;
}

int Exp()
{
    if (AddExp())
    {
        return 1;
    }
    myerror();
    return -1;
}

int LVal()
{
    if (token == tok_ID)
    {
        advance();
        while (token == tok_LSQUARE)
        {
            advance();
            if (Exp)
            {
                if (token == tok_RSQUARE)
                {
                    advance();
                    continue;
                }
                myerror();
                return -1;
            }
            myerror();
            return -1;
        }
        return 1;
    }
    myerror();
    return -1;
}

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