#include<stdio.h>

int main()
{
    int tc,a,b,c,cn;
    scanf("%d",&tc);

    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if((a*a + b*b == c*c) || (a*a + c*c == b*b ) || (c*c + b*b == a*a) )
        {
            printf("Case %d: yes\n",cn);
        }

        else printf("Case %d: no\n",cn);
    }

    return 0;
}
