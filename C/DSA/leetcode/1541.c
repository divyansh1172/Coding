#include <string.h>
#include <stdio.h>
int minInsertions(char *s)
{
    int n = strlen(s);
    char stack[4];
    int top = 0, cost = 0;
    for (int i = 0; i < n; i++)
    {
        // push to stack if empty
        if (top == 0)
            stack[top++] = s[i];

        else if (top == 1)
        {
            if (stack[top - 1] == '(')
            {
                if (s[i] == '(')
                {
                    cost += 2;
                    top=1;
                    stack[0]='(';
                }
                else
                {
                    stack[top++] = ')';
                }
            }
            else
            {
                if (s[i] == ')')
                {
                    top = 0;
                    cost++;
                }
                else
                {
                    stack[0] = '(';
                    cost += 2;
                }
            }
        }
        else
        {
            if (s[i] == ')')
                top = 0;
            else
            {
                cost++;
                stack[0]='(';
                top = 1;
            }
        }
    }
    if (top == 1)
        cost += 2;
    else if (top == 2)
        cost += 1;

    return cost;
}

int main()
{
    printf("%d\n", minInsertions("(()))"));
    printf("%d\n", minInsertions("())"));
    printf("%d\n", minInsertions("))())("));
    printf("%d\n", minInsertions("(()))(()))()())))"));
    return 0;
}