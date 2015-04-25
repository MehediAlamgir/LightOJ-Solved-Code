#include <stdio.h>

int main()
{
	//freopen("chk.txt","r",stdin);

	int tc,cn,x1,y1,x2,y2,m,x,y,i;
	scanf("%d",&tc);
	for(cn=1;cn<=tc;cn++)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

		scanf("%d",&m);

		printf("Case %d:\n",cn);

		for(i=1;i<=m;i++)
		{

			scanf("%d %d",&x,&y);
			if( (x>x1 && y>y1)&& (x<x2 && y<y2) )
			printf("Yes\n");
			else printf("No\n");
		}


	}

	return 0;


}
