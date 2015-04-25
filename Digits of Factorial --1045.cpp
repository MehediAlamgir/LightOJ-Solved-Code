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
#define size 1000001

using namespace std;
double save[size];

int main()
{
    //freopen("chk.txt","r",stdin);
    double save[size];
     long long tc,cn,num,d,i,b,res;
    save[0]=0;

    for(i=1;i<=size;i++)
    save[i]=save[i-1] + log(i);

    scanf("%lld",&tc);
    for(cn=1;cn<=tc;cn++)
    {
        scanf("%lld %lld",&num,&b);
        res=save[num]/log(b);
        //res +=1;

        printf("Case %lld: %lld\n",cn,res+1);
    }

    return 0;

}
