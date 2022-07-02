typedef struct _ast ast;
typedef struct _ast *past;
struct _ast
{
    char ivalue;
    char *nodeType;
    past left;
    past right;
};

past newAstNode()
{
    past node = malloc(sizeof(ast));
    if (node == NULL)
    {
        printf("run out of memory.\n");
        exit(0);
    }
    memset(node, 0, sizeof(ast));
    return node;
}

past LAndExp();
past EqExp();
past RelExp();
past MulExp();
past UnaryOp();
past FuncRParams();
past UnaryExp();
past Number();
past PrimaryExp();
past LOrExp();
past AddExp();
past Cond();
past Exp();
past LVal();
past Stmt();
past BlockItem();
past Block();
past FuncFParam();
past FuncFParams();
past FuncType();
past InitVal();
past VarDef();
past ConstInitVal();
past ConstExp();
past ConstDef();
past BType();
past VarDecl();
past ConstDecl();
past FuncDef();
past Decl();
past CompUnit();