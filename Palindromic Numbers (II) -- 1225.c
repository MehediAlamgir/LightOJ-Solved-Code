#include<stdio.h>

int main()
{
    int tc,cn,n,n1,reminder,reverse=0;
    scanf("%d",&tc);

    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d",&n);
        n1=n;

        while(n>0)
        {
            reminder= n % 10;
            reverse= (reverse * 10) + reminder;
            n=n / 10;


        }

        if( n1 == reverse)
            {
                printf("Case %d: Yes\n",cn);
            }

            else  printf("Case %d: No\n",cn);

            n=0;
            reverse=0;
            reminder=0;


    }
    return 0;
}
