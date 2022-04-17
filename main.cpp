#include <iostream>
#include <map>
#include <string>
#include "simpleCharStack.h"
#include <cmath>
using namespace std;

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'|| c == '(' || c == ')')
        return true;
    else
        return false;
}
bool isOperand(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

int doOper(int a, char oper, int b){
    switch(oper){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        case '^':
            return pow(a,b);
        default:
            return 0;
    };

}


int calculateInfixForm(string infixForm){
    map<char,int> precedence;
    precedence['+'] = 3;
    precedence['-'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['^'] = 1;
    precedence['('] = -1;
    //precedence[')'] = 0;
    Stack<char> operators;
    Stack<int> operands;
    for(auto c:infixForm){
        if(isOperand(c)){ //если просто число
            operands.AddEl((int)c - '0');
        }else if(isOperator(c) && (operators.CurrentLength()==0 or c=='(')){ //если это оператор и длина 0 или это скобка
            operators.AddEl(c);
        }else{ //если это оператор (не открывающаяся скобка) в непустом стеке операторов
            char operator1,operator2 = c;
            operators.TakeEl(operator1);
            if(precedence[operator1]>precedence[operator2]){ //если приоритет того что было в стеке выше
                operators.AddEl(operator1);
                operators.AddEl(operator2);
            }else if( c != ')' && precedence[operator1]<=precedence[operator2]){ //если это не закрывающаяся скобка и приоритет того что было ниже или такой же
                //вычислим a oper b
                int b;
                operands.TakeEl(b);
                int a;
                operands.TakeEl(a);

                operands.AddEl(doOper(a,c,b));
                operators.AddEl(c);

            }else{ //закрывающаяся скобка выталкивает все до открывающейся скобки
                //в operator 1 лежит верхушка стека, в 2 - ")"
                while(operator1!='('){
                    operator2 = operator1;

                    //действуем
                    int b;
                    operands.TakeEl(b);
                    int a;
                    operands.TakeEl(a);

                    operands.AddEl(doOper(a,operator2,b));


                    operators.TakeEl(operator1);
                }
            }

        }
    }
    while(operators.CurrentLength()>0){
        char oper;
        operators.TakeEl(oper);
        int b;
        operands.TakeEl(b);
        int a;
        operands.TakeEl(a);
        operands.AddEl(doOper(a,oper,b));
    }
    int result;
    operands.TakeEl(result);
    return result;

}

int main() {
    cout<<calculateInfixForm("1+2*(3+4)");
    return 0;
}
