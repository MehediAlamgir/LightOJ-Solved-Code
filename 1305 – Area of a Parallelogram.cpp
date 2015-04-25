#include <set>
#include <stdio.h>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("chk.txt","r",stdin);
	int tc,cn,x1,y1,x2,y2,x3,y3,x4,y4,A;

	scanf("%d",&tc);

	for(cn=1;cn<=tc;cn++)
	{
		scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);

		x4=x1+x3-x2;
		y4=y1+y3-y2;


		A= abs( (x2*y1)-(x2*y4)-(y2*x1)+(y2*x4)+(x1*y4)-(x4*y1)  ); // AREA = 2 * trivuj BAD (OR BCD) [ S U AHMED SOLUTION PAGE 21(CHP :1.3 / NO 24) ]


		printf("Case %d: %d %d %ld\n",cn,x4,y4,A);
	}

	return 0;

}
