#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rdparser.h"

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

char *typeLAndExp = "LAndExp";
char *typeEqExp = "EqExp";
char *typeRelExp = "RelExp";
char *typeMulExp = "MulExp";
char *typeUnaryOp = "UnaryOp";
char *typeFuncRParams = "FuncRParams";
char *typeUnaryExp = "UnaryExp";
char *typeNumber = "Number";
char *typePrimaryExp = "PrimaryExp";
char *typeLOrExp = "LOrExp";
char *typeAddExp = "AddExp";
char *typeCond = "Cond";
char *typeExp = "Exp";
char *typeLVal = "LVal";
char *typeStmt = "Stmt";
char *typeBlockItem = "BlockItem";
char *typeBlock = "Block";
char *typeFuncFParam = "FuncFParam";
char *typeFuncFParams = "FuncFParams";
char *typeFuncType = "FuncType";
char *typeInitVal = "InitVal";
char *typeVarDef = "VarDef";
char *typeConstInitVal = "ConstInitVal";
char *typeConstExp = "ConstExp";
char *typeConstDef = "ConstDef";
char *typeBType = "BType";
char *typeVarDecl = "VarDecl";
char *typeConstDecl = "ConstDecl";
char *typeFuncDef = "FuncDef";
char *typeDecl = "Decl";
char *typeCompUnit = "CompUnit";
char *typeIdent = "Ident";

// typedef struct _ast ast;
// typedef struct _ast *past;
// struct _ast
// {
//     char ivalue;
//     char *nodeType;
//     past left;
//     past right;
// };

// past newAstNode()
// {
//     past node = malloc(sizeof(ast));
//     if (node == NULL)
//     {
//         printf("run out of memory.\n");
//         exit(0);
//     }
//     memset(node, 0, sizeof(ast));
//     return node;
// }

// past newIdent(char ivalue)
// {
//     past var = newAstNode();
//     var->ivalue = ivalue;
//     return var;
// }

past newLAndExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeLAndExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newEqExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeEqExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newRelExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeRelExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newMulExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeMulExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newUnaryOp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeUnaryOp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newFuncRParams(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeFuncRParams;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newUnaryExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeUnaryExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newNumber(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeNumber;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newPrimaryExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typePrimaryExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newLOrExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeLOrExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newAddExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeAddExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newCond(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeCond;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newLVal(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeLVal;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newStmt(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeStmt;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newBlockItem(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeBlockItem;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newBlock(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeBlock;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newFuncFParam(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeFuncFParam;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newFuncFParams(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeFuncFParams;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newFuncType(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeFuncType;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newInitVal(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeInitVal;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newVarDef(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeVarDef;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newConstInitVal(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeConstInitVal;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newConstExp(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeConstExp;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newConstDef(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeConstDef;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newBType(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeBType;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newVarDecl(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeVarDecl;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newConstDecl(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeConstDecl;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newFuncDef(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeFuncDef;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newDecl(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeDecl;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}
past newCompUnit(char ivalue, past left, past right)
{
    past var = newAstNode();
    var->nodeType = typeCompUnit;
    var->ivalue = ivalue;
    var->left = left;
    var->right = right;
    return var;
}

past LAndExp()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = EqExp();
    if (left != NULL)
    {
        return newLAndExp(NULL, left, right);
    }
    left = LAndExp();
    if (left != NULL)
    {
        tmp->left = left;
        if (token == tok_AND)
        {
            tmp->ivalue = yylval;
            advance();
            right = EqExp();
            if (right != NULL)
            {
                tmp->right = right;
                return tmp;
            }
        }
        return NULL;
    }
    return NULL;
}

past EqExp()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = RelExp();
    if (left != NULL)
    {
        return newEqExp(NULL, left, right);
    }
    left = EqExp();
    if (left != NULL)
    {
        tmp->left = left;
        if (token == tok_EQ || token == tok_NOTEQ)
        {
            tmp->ivalue = yylval;
            advance();
            right = RelExp();
            if (right != NULL)
            {
                tmp->right = right;
                return tmp;
            }
        }
        return NULL;
    }
    return NULL;
}

past RelExp()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = AddExp();
    if (left != NULL)
    {
        return newRelExp(NULL, left, right);
    }
    left = RelExp();
    if (left != NULL)
    {
        tmp->left = left;
        if (token == tok_LESS || token == tok_GREAT || token == tok_LESSEQ || token == tok_GREATEQ)
        {
            tmp->ivalue = yylval;
            advance();
            right = AddExp();
            if (right != NULL)
            {
                tmp->right = right;
                return tmp;
            }
        }
        return NULL;
    }
    return NULL;
}

past MulExp()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = UnaryExp();
    if (left != NULL)
    {
        return newMulExp(NULL, left, right);
    }
    left = MulExp();
    if (left != NULL)
    {
        tmp->left = left;
        if (token == tok_MUL || token == tok_DIV || token == tok_MODULO)
        {
            tmp->ivalue = yylval;
            advance();
            right = UnaryExp();
            if (right != NULL)
            {
                tmp->right = right;
                return tmp;
            }
        }
        return NULL;
    }
    return NULL;
}

past UnaryOp()
{
    past left = NULL;
    past right = NULL;
    if (token == tok_ADD || token == tok_SUB || token == tok_NOT)
    {
        left = newUnaryOp(yylval, NULL, NULL);
        advance();
        return left;
    }
    return NULL;
}

past FuncRParams()
{
    past left = NULL;
    past right = NULL;
    left = Exp();
    if (left != NULL)
    {
        past tmp = left;
        while (token == tok_COMMA)
        {
            tmp = tmp->left;
            advance();
            tmp = Exp();
            if (tmp != NULL)
            {
                continue;
            }
            return NULL;
        }
        return newFuncRParams(NULL, left, right);
    }
    return NULL;
}

past UnaryExp()
{
    past left = NULL;
    past right = NULL;
    left = PrimaryExp();
    if (left != NULL)
    {
        return newUnaryExp(NULL, left, right);
    }
    if (token == tok_ID)
    {
        past tmp = newUnaryExp(yylval, NULL, NULL);
        advance();
        if (token == tok_LPAR)
        {
            advance();
            left = FuncRParams();
            if (token == tok_RPAR)
            {
                advance();
                tmp->left = left;
                return tmp;
            }
        }
        return NULL;
    }
    return NULL;
}

past Number()
{
    past left = NULL;
    past right = NULL;
    if (token == tok_INTEGER)
    {
        advance();
        return newNumber(yylval, left, right);
    }
    return NULL;
}

past PrimaryExp()
{
    past left = NULL;
    past right = NULL;
    if (token == tok_LPAR)
    {
        advance();
        left = Exp();
        if (left != NULL)
        {
            if (token == tok_RPAR)
            {
                advance();
                return newPrimaryExp(NULL, left, right);
            }
        }
        return NULL;
    }
    left = LVal();
    if (left != NULL)
    {
        return newPrimaryExp(NULL, left, right);
    }
    left = Number();
    if (left != NULL)
    {
        return newPrimaryExp(NULL, left, right);
    }
    return NULL;
}

past LOrExp()
{
    past left = NULL;
    past right = NULL;
    left = LAndExp();
    if (left != NULL)
    {
        return newLOrExp(NULL, left, right);
    }
    left = LOrExp();
    if (left != NULL)
    {
        if (token == tok_OR)
        {
            advance();
            right = LAndExp();
            if (right != NULL)
            {
                return newLOrExp(NULL, left, right);
            }
        }
        return NULL;
    }
    return NULL;
}

past AddExp()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = MulExp();
    if (left != NULL)
    {
        return newAddExp(NULL, left, right);
    }
    left = AddExp();
    if (left != NULL)
    {
        if (token == tok_ADD)
        {
            tmp = newAddExp("+", left, NULL);
            advance();
        }
        else if (token == tok_SUB)
        {
            tmp = newAddExp("-", left, NULL);
            advance();
        }
        right = MulExp();
        if (right != NULL)
        {
            tmp->right = right;
            return tmp;
        }
        return NULL;
    }
    return NULL;
}

past Cond()
{
    past left = NULL;
    past right = NULL;
    left = LOrExp();
    if (left != NULL)
    {
        return newCond(NULL, left, right);
    }
    return NULL;
}

past Exp()
{
    past left = NULL;
    past right = NULL;
    left = AddExp();
    if (left != NULL)
    {
        return newExp(NULL, left, right);
    }
    return NULL;
}

past LVal()
{
    past left = NULL;
    past right = NULL;
    if (token == tok_ID)
    {
        past tmp = newLVal(yylval, NULL, NULL);
        advance();
        left = tmp;
        while (token == tok_LSQUARE)
        {
            left = left->left;
            advance();
            left = Exp();
            if (left != NULL)
            {
                if (token == tok_RSQUARE)
                {
                    advance();
                    continue;
                }
                return NULL;
            }
            return NULL;
        }
        return tmp;
    }
    return NULL;
}

past Stmt()
{
    past left = NULL;
    past right = NULL;
    left = LVal();
    if (left != NULL)
    {
        if (token == tok_ASSIGN)
        {
            advance();
            right = Exp();
            if (right != NULL)
            {
                if (token == tok_SEMICOLON)
                {
                    advance();
                    return newStmt(NULL, left, right);
                }
            }
        }
        return NULL;
    }

    left = Exp();
    if (token == tok_SEMICOLON)
    {
        {
            return newStmt(NULL, left, right);
        }
        return NULL;
    }

    // left = Exp();
    // if (left != NULL)
    // {
    //     if (token == tok_SEMICOLON)
    //     {
    //         return newStmt(NULL, left, right);
    //     }
    //     return NULL;
    // }
    // else
    // {
    //     if (token == tok_SEMICOLON)
    //     {
    //         return newStmt(NULL, left, right);
    //     }
    // }

    left = Block();
    if (left != NULL)
    {
        return newStmt(NULL, left, right);
    }

    if (token == tok_IF)
    {
        past tmp = newStmt("if", NULL, NULL);
        advance();
        if (token == tok_LPAR)
        {
            advance();
            left = Cond();
            if (left != NULL)
            {
                if (token == tok_RPAR)
                {
                    advance();
                    left->left = Stmt();
                    if (left->left != NULL)
                    {
                        tmp->left = left;
                        if (token == tok_ELSE)
                        {
                            advance();
                            right = Stmt();
                            if (right != NULL)
                            {
                                tmp->right = right;
                                right->ivalue = "else";
                                return tmp;
                            }
                            else
                            {
                                return NULL;
                            }
                        }
                        return tmp;
                    }
                }
            }
        }
        return NULL;
    }

    if (token == tok_WHILE)
    {
        past tmp = newStmt("while", NULL, NULL);
        advance();
        if (token == tok_LPAR)
        {
            advance();
            tmp->left = Cond();
            if (tmp->left != NULL)
            {
                if (token == tok_RPAR)
                {
                    advance();
                    tmp->right = Stmt();
                    if (tmp->right != NULL)
                    {
                        return tmp;
                    }
                }
            }
        }
        return NULL;
    }

    if (token == tok_BREAK)
    {
        past tmp = newStmt("break", NULL, NULL);
        advance();
        if (token == tok_SEMICOLON)
        {
            return tmp;
        }
        return NULL;
    }

    if (token == tok_CONTINUE)
    {
        past tmp = newStmt("continue", NULL, NULL);
        advance();
        if (token == tok_SEMICOLON)
        {
            return tmp;
        }
        return NULL;
    }

    if (token == tok_RETURN)
    {
        past tmp = newStmt("return", NULL, NULL);
        advance();
        tmp->left = Exp();
        if (token == tok_SEMICOLON)
        {
            return tmp;
        }
        return NULL;
    }
    return NULL;
}

past BlockItem()
{
    past left = NULL;
    past right = NULL;
    left = Decl();
    if (left != NULL)
    {
        return newBlockItem(NULL, left, right);
    }
    left = Stmt();
    if (left != NULL)
    {
        return newBlockItem(NULL, left, right);
    }
    return NULL;
}

past Block()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    if (token == tok_LBRACKET)
    {
        advance();
        left = BlockItem();
        tmp = left;
        while (tmp != NULL)
        {
            tmp = tmp->left;
            tmp = BlockItem();
        }
        if (token == tok_RBRACKET)
        {
            return newBlock(NULL, left, right);
        }
    }
    return NULL;
}

past FuncFParam()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    tmp = BType();
    if (tmp != NULL)
    {
        if (token == tok_ID)
        {
            left = newFuncFParam(yylval, tmp, NULL);
            advance();
            if (token == tok_LSQUARE)
            {
                advance();
                if (token == tok_RSQUARE)
                {
                    advance();
                    tmp = left;
                    while (token == tok_LSQUARE)
                    {
                        tmp = tmp->right;
                        advance();
                        tmp = Exp();
                        if (tmp != NULL)
                        {
                            if (token == tok_RSQUARE)
                            {
                                advance();
                                continue;
                            }
                        }
                        return NULL;
                    }
                }
                return NULL;
            }
        }
        return left;
    }
    return NULL;
}

past FuncFParams()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = FuncFParam();
    if (left != NULL)
    {
        tmp = left;
        while (token == tok_COMMA)
        {
            tmp = tmp->left;
            advance();
            tmp = FuncFParam();
            if (tmp != NULL)
            {
                continue;
            }
            else
            {
                return NULL;
            }
        }
        return newFuncFParams(NULL, left, right);
    }
    return NULL;
}

past FuncType()
{
    past left = NULL;
    past right = NULL;
    if (token == tok_VOID)
    {
        advance();
        return newFuncType("void", left, right);
    }
    else if (token == tok_INT)
    {
        advance();
        return newFuncType("int", left, right);
    }
    return NULL;
}

past InitVal()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = Exp();
    if (left != NULL)
    {
        return newInitVal(NULL, left, right);
    }
    if (token == tok_LBRACKET)
    {
        advance();
        left = InitVal();
        if (left != NULL)
        {
            tmp = left;
            while (token == tok_COMMA)
            {
                tmp = tmp->left;
                advance();
                tmp = InitVal();
                if (tmp != NULL)
                {
                    continue;
                }
                else
                {
                    return NULL;
                }
            }
        }
        if (token == tok_RBRACKET)
        {
            advance();
            return newInitVal(NULL, left, right);
        }
    }
    return NULL;
}

past VarDef()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    if (token == tok_ID)
    {
        left = newVarDef(yylval, NULL, NULL);
        tmp = left;
        advance();
        while (token == tok_LSQUARE)
        {
            tmp = tmp->left;
            advance();
            tmp = ConstExp();
            if (token == tok_RSQUARE)
            {
                advance();
                continue;
            }
            return NULL;
        }
        if (token == tok_ASSIGN)
        {
            advance();
            left->right = InitVal();
            if (left->right != NULL)
            {
                return left;
            }
            return NULL;
        }
        return left;
    }
    return NULL;
}

past VarDecl()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = BType();
    if (BType != NULL)
    {
        right = VarDef();
        if (right != NULL)
        {
            tmp = right;
            while (token == tok_COMMA)
            {
                advance();
                tmp->left = VarDef();
                tmp = tmp->left;
                if (tmp != NULL)
                {
                    continue;
                }
                return NULL;
            }
            if (token == tok_SEMICOLON)
            {
                return newVarDecl(NULL, left, right);
            }
        }
    }
    return NULL;
}

past ConstInitVal()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    left = ConstExp();
    if (left != NULL)
    {
        return newConstInitVal(NULL, left, right);
    }
    if (token == tok_LBRACKET)
    {
        advance();
        left = ConstInitVal();
        if (left != NULL)
        {
            tmp = left;
            while (token == tok_COMMA)
            {
                advance();
                tmp->left = ConstInitVal();
                tmp = tmp->left;
                if (tmp != NULL)
                {
                    continue;
                }
                return NULL;
            }
        }
        if (token == tok_RSQUARE)
        {
            advance();
            return newConstInitVal(NULL, left, right);
        }
    }
    return NULL;
}

past ConstExp()
{
    past left = NULL;
    past right = NULL;
    left = AddExp();
    if (left != NULL)
    {
        return newConstExp(NULL, left, right);
    }
    return NULL;
}

past ConstDef()
{
    past left = NULL;
    past right = NULL;
    past tmp = NULL;
    past l = NULL;
    if (token == tok_ID)
    {
        left = newConstDef(yylval, left, right);
        l = left;
        advance();
        while (token == tok_LSQUARE)
        {
            l = l->left;
            advance();
            tmp = ConstExp();
            if (tmp != NULL)
            {
                if (token == tok_RSQUARE)
                {
                    advance();
                    l = tmp;
                    continue;
                }
                return NULL;
            }
            return NULL;
        }
        if (token == tok_ASSIGN)
        {
            advance();
            right = ConstInitVal();
            if (right != NULL)
            {
                left->right = right;
                return left;
            }
        }
        return NULL;
    }
    return NULL;
}

past BType()
{
    past left = NULL;
    past right = NULL;
    if (token == tok_INT)
    {
        char tmp = yylval;
        advance();
        return newBType(tmp, left, right);
    }
    return NULL;
}

past ConstDecl()
{
    past left = NULL;
    past right = NULL;
    if (token == tok_CONST)
    {
        advance();
        left = BType();
        if (left != NULL)
        {
            right = ConstDef();
            if (right != NULL)
            {
                past tmp = right;
                while (token == tok_COMMA)
                {
                    advance();
                    tmp = tmp->left;
                    tmp = ConstDef();
                    if (tmp != NULL)
                    {
                        continue;
                    }
                    return NULL;
                }
                if (token == tok_SEMICOLON)
                {
                    return newConstDecl(left->nodeType, left, right);
                }
            }
        }
        return NULL;
    }
    return NULL;
}

past FuncDef()
{
    past left = NULL;
    past right = NULL;
    left = FuncType();
    if (left != NULL)
    {
        if (token == tok_ID)
        {
            left->left = newFuncDef(yylval, NULL, NULL);
            advance();
            if (token == tok_LPAR)
            {
                advance();
                left->left->left = FuncFParams();
                if (token == tok_RPAR)
                {
                    advance();
                    past tmp = Block();
                    if (tmp != NULL)
                    {
                        left->left->right = tmp;
                        return left;
                    }
                }
            }
        }
    }
    return NULL;
}

past Decl()
{
    past left = NULL;
    past right = NULL;
    left = ConstDecl();
    if (left != NULL)
    {
        return newDecl(NULL, left, right);
    }
    left = VarDecl();
    if (left != NULL)
    {
        return newDecl(NULL, left, right);
    }
    return NULL;
}

past CompUnit()
{
    past left = NULL;
    past right = NULL;
    left = Decl();
    if (left != NULL)
    {
        // printf("%s\n",left->left->nodeType);
        return newCompUnit(NULL, left, right);
    }
    left = FuncDef();
    if (left != NULL)
    {
        return newCompUnit(NULL, left, right);
    }
    return NULL;
}

void showAst(past node, int nest)
{
	// if(node == NULL)
	// 	return;

	// int i = 0;
	// for(i = 0; i < nest; i ++)
	// 	printf("  ");
	// if(strcmp(node->nodeType, "intValue") == 0)
	// 	printf("%s %d\n", node->nodeType, node->ivalue);
	// else if(strcmp(node->nodeType, "expr") == 0)
	// 	printf("%s '%c'\n", node->nodeType, (char)node->ivalue);
	// showAst(node->left, nest+1);
	// showAst(node->right, nest+1);

}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        if (!(yyin = fopen(argv[1], "r")))
        {
            perror(argv[1]);
            return 1;
        }
    }
    past r;
    token = 1;
    while (token != 0)
    {
        advance();
        r = CompUnit();
        // showAst(r,0);
        if(r!=NULL){
            printf("%s",r->nodeType);
        }
        // if (r)
        // {
        //     printf("Unit\n");
        // }
        // else
        // {
        //     myerror();
        // }
    }
    // past rr =newCompUnit('a',NULL,NULL);
    // printf("%s\n",rr->nodeType);
    return 0;
}
