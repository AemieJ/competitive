#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
#define SIZE 50
//GIVING RUNTIME ERROR IN SPOJ

char stack[SIZE];
int top = -1;
char output[SIZE];

void push(char character)
{
   if(top >= SIZE-1)
        printf("STACK OVERFLOW");
    else
    {
        top++;
        stack[top]  = character;
    }

}

void pop(char character)
{
    if(top <= -1)
        printf("STACK UNDERFLOW");
    else 
        top--;
}

int isOperator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

int precedence(char digit)
{
    if( digit == '^')
        return 3;
    if (digit == '*' || digit =='/')
        return 2;
    if(digit == '+' || digit == '-')
        return 1;        
}

char* infixToPostfix(char expression[]) 
{
    int length = strlen(expression);
    int counter = 0 , out = 0;
    while(counter < length)
    {
        char character = expression[counter];
        if( character == '(')
            push(character);

        else if (isdigit(character) || isalpha(character))
        {
            output[out] = character;
            out++;
        }
        else if(isOperator(character)==1)
        {
            //push(character);
            for(int i=top ; i>=0 ; i--)
            {
                char newCharacter = stack[i];
                if(isOperator(newCharacter) && precedence(newCharacter) >= precedence(character) && newCharacter != '(')
                {
                    output[out] = newCharacter;
                    out++;
                    pop(newCharacter);
                }
                if (newCharacter == '(')
                    break;
            }
            push(character);
        }

        else if(character == ')')
        {
            for(int i=top ; i >= 0 ; i--)
            {
                char newCharacter = stack[i];
                if (newCharacter != '(')
                {
                    output[out] = newCharacter;
                    out++;
                    pop(newCharacter);
                }
                if(newCharacter == '(')
                {
                    pop(newCharacter); 
                    break;
                }              

            }
        }
        counter++;
    }
    
    if (top != -1)
    {
        printf("Your expression is invalid");
        output[0] = '\0';
    }
    return output;
}


int main()
{
    int test;
    scanf("%d\n",&test);
    for(int i=0 ; i < test ; i++) 
    {
        char infix[SIZE], postfix[SIZE];
        fgets(infix, SIZE + 1, stdin);

        int length = strlen(infix) + 2;
        for (int i = length - 3; i > 0; i--)
        {
            infix[i] = infix[i - 1];
        }
        infix[0] = '(';
        infix[length - 2] = ')';
        infix[length - 1] = '\0';

        strncpy(postfix, infixToPostfix(infix), SIZE);
        if (postfix[0] != '\0')
            printf("%s\n", infixToPostfix(infix));
    }

    return 0;
}
