#include<bits/stdc++.h>

using namespace std;

/*======================================= Macro Start====================================================*/

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define count_one(a) __builtin_popcount(a)  // Returns the number of set bits(1) in a number(a). In long long use __builtin_popcountll(a)
#define parity(i)   __builtin_parity(i)  //even parity 0 and odd parity 1
#define blz(a)   __builtin_clz(a) //Returns the number of leading zeroes in a number(a)
#define btz(a)   __builtin_ctz(a) //Returns the number of trailing zeroes in a number(a)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))

/*======================================= Macro End====================================================*/

/*====================================== CONSTANT Start===================================================*/

#define inf (1<<30) //infinity value
#define eps 1e-9
#define mod 10007
#define siz 105

/*====================================== CONSTANT End===================================================*/

int main()
{
    int tc,cn,n,w[siz],b[siz],res,a;
    scanf("%d",&tc);

    for(cn=1;cn<=tc;cn++)
    {
        res=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&w[i]);

         for(int j=0;j<n;j++)
            scanf("%d",&b[j]);

        for(int k=0;k<n;k++)
        {
            a=b[k]-w[k]-1;
            res ^= a;
        }

        if(res==0)
            printf("Case %d: black wins\n",cn);
        else
              printf("Case %d: white wins\n",cn);
    }

    return 0;
}
