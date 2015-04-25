#include<stdio.h>

int main ()
{
    int tc,cn,sum,sn,a[1000],i;


    scanf("%d",&tc);


    for(cn=1;cn<=tc;cn++)
    {


	  scanf("%d",&sn);
	  sum=0;
	  for(i=1;i<=sn;i++)
       {
		 scanf("%d",&a[i]);
		if (a[i]>0)
			sum=sum+a[i];
       }


	  printf("Case %d: %d\n",cn,sum);




    }
    return 0;

}
