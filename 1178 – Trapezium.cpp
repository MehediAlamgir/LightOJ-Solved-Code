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

	int tc,cn;
	double a,b,c,d,s,area,k;

	scanf("%d",&tc);
	for(cn=1;cn<=tc;cn++)
	{
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		s=0.5*(c+a+d+b);
		k=sqrt(  (s-a)*(s-c)* (s-a-d)*(s-a-b) );
		area=((c+a)/abs(a-c)) * k;

		printf("Case %d: %lf\n",cn,area);
	}


	return 0;

}
