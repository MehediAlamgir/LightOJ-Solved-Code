/*

Solution: Firstly write 1 to 15 or more number then observe the number pattern.Among them Always 2 numbers
from every 3 number is divisible by 3. Let , n is divisible by 3 , then always also  (n-1) is divisible by 3
AND (n+1) will not be divisible by 3. When a==b , then a and (a+1) will be divisible by 3.

So just observe the first 15/16 number, a pattern will be generated.


*/

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

#define INF (1<<30) //infinity value
#define EPS 1e-9
#define MOD 10007
#define SIZ 1005

/*====================================== CONSTANT End===================================================*/

long long solve(long long n1, long long n2);

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc,cn;
    long long n1,n2,ans,ans1,ans2;

    cin>>tc;

    for(cn=1;cn<=tc;cn++)
    {
        cin>>n1>>n2;

        if(n1==n2)
        {
            ans=solve(n1,n2);
        }

        else
        {
           ans1 = solve(1,n2);
           ans2 = solve(1,n1-1);

           ans = ans1-ans2;
        }


        cout<<"Case "<<cn<<": "<<ans<<endl;

    }

    return 0;
}

long long solve(long long a,long long b)
{
    long long p,q,totalP,totalQ,res;

    if(a==b)
    {
        if(a%3==0 || (a+1)%3==0 )
            res =1;

        else
            res=0;
    }

    else
    {
        if(b%3==0 || (b-1)%3==0)
        {
            res = b/3;
            res *= 2;

        }

        else if((b+1) % 3 ==0)
        {
            res = b/3;
            res = (res*2)+1;

        }
    }

    return res;

}
