#include<stdio.h>

int main()
{
	int num,p,q,c,tc,cn;

	scanf("%d",&tc);

	for(cn=1;cn<=tc;cn++)
	{
	scanf("%d",&num) ;

	c=0;
	while(num !=0)
		{
		   p= num;
		num=num/2;
		q=p-(2*num);
		if(q==1)
		c++;

		}

		if(c %2 == 0 )

		printf("Case %d: even\n",cn);

		else printf("Case %d: odd\n",cn);

	}

return 0;

}

