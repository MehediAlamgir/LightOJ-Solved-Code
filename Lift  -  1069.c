#include<stdio.h>
#include<math.h>

int main()
{
    int tc,cn,c,n1,n2,result;

    scanf("%d",&tc);

    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d %d",&n1,&n2);

        c=abs(n2-n1);
        result=((c*4)+3+5+3+(n1*4)+3+5);
        printf("Case %d: %d\n",cn,result);


    }

    return 0;
}
