// 12, 12, 12, +, *, 12, -, 12, + 
//is the example of input postfix exapression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

struct STACK
{
    double data[MAX_SIZE];
    int cur_size = 0;
    void push(double x)
    {
        if (cur_size == MAX_SIZE)
            printf("Full\n");
        else
        {
            data[cur_size] = x;
            cur_size++;
        }
    }

    // returns the popped value
    void pop()
    {
        if (cur_size == 0)
            printf("Empty\n");
        else
        {
            cur_size--;
        }
    }
} st;

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return 0;
    else
        return 1;
}

double eval(char *postfix)
{
    // r stores the value of each operation
    double x1, x2, r = 1; 
	int i, j;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] == ',')
        {
            double flag = 0, value_of_extracted_int = 0, Positional_value = 1;
            for (j = i - 1; (postfix[j] >= '0' && postfix[j] <= '9') ; j--)
            {
                    value_of_extracted_int += (double)(postfix[j] - '0') * Positional_value;
                    Positional_value *= 10;
                    flag = 1;
            }
            if(flag == 1) st.push(value_of_extracted_int);
           // printf("n %lf\n", value_of_extracted_int);
        }
        else if (isOperand(postfix[i]) == 0)
        {
            // x1 x2
            x2 = st.data[st.cur_size-1];
            st.pop();
            x1 = st.data[st.cur_size-1];
            st.pop();
           //printf("%lf %c %lf = ", x1, postfix[i], x2);
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            case '^':
                r = 1;
                for (int i = 0; i < x2; i++)
                    r *= x1;
                break;
            }
           // printf(" %lf\n", r);
            st.push(r);
        }
    }
    return st.data[0];
}

int main()
{
    char post[90000];
    printf("Enter the postix expression: ");
    gets(post);
    printf("The answer is %.0lf\n", eval(post));
}

//2, 1, +, 5, 1, -, *, 7, 3, +, /, 2, 3, +, *
