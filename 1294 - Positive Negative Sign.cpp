/*
Solution: Look at the pattern

Consider the example from the problem description:
-1 -2 -3 +4 +5 +6 -7 -8 -9 +10 +11 +12

Re-arrange the numbers as follows, which is equivalent:
(-1 +4) (-2 +5) (-3 +6) (-7 +10) (-8 +11) (-9 +12)

Now observe what happens

difference of all parentheses are 3 and total block is 6 (n/2) which is (12/2);

So sum = 3*6 == 18

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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

   // input;

    int n,m,tc,cn;

    cin>>tc;

    for(cn=1;cn<=tc;cn++)
    {
        cin>>n>>m;

        long long dif = (-1 + (1+m) );
        long long res = dif * (n/2);


        cout<<"Case "<<cn<<": "<<res<<endl;

    }

    return 0;
}
