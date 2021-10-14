%{
#include    <stdio.h>
#define     CONSTANT_FLAG   1
#define     OPERATOR_FLAG   2
#define     DELIMITER_FLAG  3
#define     IDENTIFIER_FLAG 4
#define     KEYWORD_FLAG    5
int constant = 0;
int operator = 0;
int delimiter = 0;
int identifier = 0;
int keyWord = 0;
%}
    // 常数
    // [-]*[0-9]+[.]*[0-9]*
CONSTANT    ([-]*[0-9]+[.]*[0-9]*)

    // 算术运算符
    // 用于各类数值运算。包括加(+)、减(-)、乘(*)、除(/)、求余(或称模运算，%)、自增(++)、自减(--)共七种。
    // 关系运算符
    // 用于比较运算。包括大于(>)、小于(<)、等于(==)、 大于等于(>=)、小于等于(<=)和不等于(!=)六种。
    // 逻辑运算符
    // 用于逻辑运算。包括与(&&)、或(||)、非(!)三种。
    // 位操作运算符
    // 参与运算的量，按二进制位进行运算。包括位与(&)、位或(|)、位非(~)、位异或(^)、左移(<<)、右移(>>)六种。
    // 赋值运算符
    // 用于赋值运算，分为简单赋值(=)、复合算术赋值(+=,-=,*=,/=,%=)和复合位运算赋值(&=,|=,^=,>>=,<<=)三类共十一种。
    // 条件运算符
    // 这是一个三目运算符，用于条件求值(?:)。
    // 逗号运算符
    // 用于把若干表达式组合成一个表达式(，)。
    // 指针运算符
    // 用于取内容(*)和取地址(&)二种运算。
    // 求字节数运算符
    // 用于计算数据类型所占的字节数(sizeof)。
    // 特殊运算符
    // 有括号()，下标[]，成员(→，.)等几种。
    // \+|\-|\*|/|%|\+\+|\-\-|>|<|==|>=|<=|!=|&&|\|\||!|&|\||~|\^|<<|>>|=|\+=|\-=|\*=|/=|%=|&=|\|=|\^=|>>=|<<=|\?:|,|\*|&|sizeof|\->|\.
OPERATOR    ([\+]|[\-]|[\*]|[/]|[%]|[\+\+]|[\-\-]|[>]|[<]|[==]|[>=]|[<=]|[!=]|[&&]|[\|\|]|[!]|[&]|[\|]|[~]|[\^]|[<<]|[>>]|[=]|[\+=]|[\-=]|[\*=]|[/=]|[%=]|[&=]|[\|=]|[\^=]|[>>=]|[<<=]|[\?:]|[,]|[\*]|[&]|[sizeof]|[\->]|[\.])
    
    // 界符
    // 花括符    {和}     
    // 尖括符    <和>     
    // 圆括符    (和)     
    // 方括符    [和]     
    // 注释符    /*和*/     
    // 双引号    "     
    // 单引号    '
    // \{|\}|<|>|\(|\)|\[|\]|/\*|\*/|"|'
DELIMITER   (\{|\}|<|>|\(|\)|\[|\]|[/\*]|[\*/]|["]|['])
    
    // 标识符
    // 由字母（A-Z，a-z）、数字（0-9）、下划线“_”组成，并且首字符不能是数字，但可以是字母或者下划线
    // [a-zA-Z_][a-zA-Z0-9_]*
IDENTIFIER  ([a-zA-Z_][a-zA-Z0-9_]*)

    // 关键字
    // auto break case char const continue default do
    // double else enum extern float for goto if int
    // long register return short signed sizeof static
    // struct switch typedef union unsigned void volatile
    // while inline restrict _Bool _Complex _Imaginary
    // _Alignas _Alignof _Atomic _Static_assert _Noreturn
    //  _Thread_local _Generic
    // auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|inline|restrict|_Bool|_Complex|_Imaginary|_Alignas|_Alignof|_Atomic|_Static_assert|_Noreturn|_Thread_local|_Generic
KEYWORD     (auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while|inline|restrict|_Bool|_Complex|_Imaginary|_Alignas|_Alignof|_Atomic|_Static_assert|_Noreturn|_Thread_local|_Generic)
%%
{CONSTANT}      {constant++; return CONSTANT_FLAG;}
{OPERATOR}      {operator++; return OPERATOR_FLAG;}
{DELIMITER}     {delimiter++; return DELIMITER_FLAG;}
{KEYWORD}       {keyWord++; return KEYWORD_FLAG;}
{IDENTIFIER}    {identifier++; return IDENTIFIER_FLAG;}
%%
int main(){
    int flag = 0;
    while (flag=yylex()){
        switch(flag){
            case CONSTANT_FLAG:
                printf("CONSTANT: %s\n", yytext);
                continue;
            case OPERATOR_FLAG:
                printf("OPERATOR: %s\n", yytext);
                continue;
            case DELIMITER_FLAG:
                printf("DELIMITER: %s\n", yytext);
                continue;
            case IDENTIFIER_FLAG:
                printf("IDENTIFIER: %s\n", yytext);
                continue;
            case KEYWORD_FLAG:
                printf("KEYWORD: %s\n", yytext);
                continue;
        }
    }
    printf("TOTAL:\nCONSTANT:%d\nOPERATOR: %d\nDELIMITER: %d\nIDENTIFIER: %d\nKEYWORD: %d\n", constant, operator, delimiter, identifier, keyWord);
    return 0;
}
