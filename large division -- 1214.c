#include<stdio.h>

int main()
{
	//freopen("chk.txt","r",stdin);

    long long i,r,n,l,tc,cn;

    char a[2000];

    scanf("%lld",&tc);

    for(cn=1;cn<=tc;cn++)
    {

    scanf("%s%lld",&a,&n);

    l=strlen(a);

	if(a[0]=='-')
	{
		r=0;
    for(i=1;i<l;i++)
    {
		r=(r*10+a[i]-48) % n;
    }

	}
	else
	{
	r=0;
	for(i=0;i<l;i++)
    {
		r=(r*10+a[i]-48) % n;
    }

	}

    if(r==0)
    {
        printf("Case %lld: divisible\n",cn);
    }

    else printf("Case %lld: not divisible\n",cn);


    }

    return 0;
}
