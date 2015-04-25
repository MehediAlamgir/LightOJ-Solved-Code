#include<stdio.h>

int main()
{
    int tc,t=0,cn,vis,k=0;

    scanf("%d",&t);
    //printf("Case %d:\n",++k);

    for(cn=1;cn<=t;cn++)
    {

    scanf("%d",&tc);
    printf("Case %d:\n",++k);

	   int r=0,i,sum=0,t=0;
	  char c[100];

	   for(i=1;i<=tc;i++)
	   {
	   scanf("%s",&c);

	   if(c[0]=='d')
	   {
		scanf(" %d",&t);
        sum=sum+t;
		}

	    else if(c[0]=='r')
		  {

			 printf("%d\n",sum);


            }

    }



    }


    return 0;
}
