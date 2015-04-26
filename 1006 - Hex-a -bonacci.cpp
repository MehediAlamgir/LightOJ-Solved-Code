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

     int a, b, c, d, e, f;
     int dp[10001];
     int MOD;

    int fn( int n )
    {

        if( n == 0 ) return a;
        if( n == 1 ) return b;
        if( n == 2 ) return c;
        if( n == 3 ) return d;
        if( n == 4 ) return e;
        if( n == 5 ) return f;

        if(dp[n]!=-1)
        return dp[n];

        else
        {

         dp[n]=( (((((fn(n-1)+ fn(n-2) )%10000007 + fn(n-3))%10000007 + fn(n-4))%10000007 + fn(n-5))%10000007 + fn(n-6))%10000007 );

        return dp[n];
        }
    }
    int main()
     {
           // freopen("chk.txt","r",stdin);
        int n, caseno = 0, cases,i;

            /*for(i=0;i<=10000;i++)
            dp[i]=-1;*/
        scanf("%d", &cases);
        while( cases-- )
        {
			for(i=0;i<=10000;i++)
            dp[i]=-1;

            scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
            printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
        }
        return 0;
    }
