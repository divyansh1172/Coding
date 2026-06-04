#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int count_dots(char *s, int i, int n)
{
    int count = 0;

    while (i < n && s[i] == '.')
    {
        count++;
        i++;
    }

    return count;
}

char *simplifyPath(char *s)
{

    int n = strlen(s);

    char *res = (char *)malloc(n + 1);

    int count = 0;

    res[count++] = '/';

    for (int i = 1; i < n;)
    {

        // skip multiple '/'
        while (i < n && s[i] == '/')
            i++;

        if (i >= n)
            break;

        // handle dots
        if (s[i] == '.')
        {

            int start = i;

            int dots = count_dots(s, i, n);

            i += dots;

            // special only if followed by '/' or end
            if (i == n || s[i] == '/')
            {

                // "."
                if (dots == 1)
                {
                    continue;
                }

                // ".."
                else if (dots == 2)
                {

                    // remove trailing '/'
                    if (count > 1)
                        count--;

                    // go back to previous '/'
                    while (count > 0 && res[count - 1] != '/')
                        count--;

                    continue;
                }
            }

            // normal directory like "...", "..a"
            i = start;
        }

        // add '/'
        if (count > 1 && res[count - 1] != '/')
            res[count++] = '/';

        // copy directory name
        while (i < n && s[i] != '/')
        {
            res[count++] = s[i++];
        }
    }

    // remove trailing slash except root
    if (count > 1 && res[count - 1] == '/')
        count--;

    res[count] = '\0';

    return res;
}