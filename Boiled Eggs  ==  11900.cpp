#include <stdio.h>

int main()
{
    	//freopen("chk.txt","r",stdin);

	int tc,cn,n,p,q,a[100],i,j,k,sum,cnt;


	scanf("%d",&tc);

	for(cn=1;cn<=tc;cn++)
	{
		scanf("%d %d %d",&n,&p,&q);

		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}


		sum=0;

		cnt=0;
		for(i=0;i<n;i++)
		{
			sum += a[i];
			if(sum>q || cnt>=p)
			break;
			cnt++;
		}


		printf("Case %d: %d\n",cn,cnt);

		}



	return 0;

}
