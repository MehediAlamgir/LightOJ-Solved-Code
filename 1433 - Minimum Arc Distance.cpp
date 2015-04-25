#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <functional>
#include <numeric>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define PI 2*acos(0.0)
#define MAX3(a,b,c) max(a,max(b,c))
#define MIN3(a,b,c) min(a,min(b,c))
#define MAX   10000007
#define INF   1<<30 	//infinity value
#define EPS   1e-9
#define MOD   1000000007


int main()
{
    input;
    int tc,cn,ox,oy,ax,ay,bx,by;
    double O,A,B,arc,ang;

    scanf("%d",&tc);
    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d %d %d %d %d %d",&ox,&oy,&ax,&ay,&bx,&by);

        O=sqrt(((bx-ax)*(bx-ax)) + ((by-ay)*(by-ay)));
        A=sqrt(((ox-bx)*(ox-bx)) + ((oy-by)*(oy-by)));
        B=sqrt(((ox-ax)*(ox-ax)) + ((oy-ay)*(oy-ay)));

        ang=acos(((A*A)+(B*B)-(O*O)) / (2.0*A*B));  //Cosine Law
        arc=A*ang;  //s=r*angle

        printf("Case %d: %lf\n",cn,arc);
    }

	return 0;
}
