#include<stdio.h>

int main()
{
    int a,b,t,c,s;

    scanf("%d\n\n",&t);

    for(c=1;c<=t;c++){

    scanf("\n%d %d",&a,&b);
    if(a>10 ||b>10)  break;
    s=a+b;

    printf("Case %d: %d\n",c,s);
	}

    return 0;

}
