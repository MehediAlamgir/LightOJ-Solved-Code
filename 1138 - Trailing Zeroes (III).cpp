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
#define SIZ 100000005

/*====================================== CONSTANT End===================================================*/

int FactorialNoOf5(int n,int x);
int BS(int);

bool flag;

int main()
{

   int tc,cn;
   long long q,res;

   cin>>tc;
   for(cn=1;cn<=tc;cn++)
   {
       cin>>q;
       flag = 0;
       int res = BS(q);

       if(flag)
            cout<<"Case "<<cn<<": "<<res<<endl;
        else
            cout<<"Case "<<cn<<": impossible"<<endl;

   }

    return 0;
}

int FactorialNoOf5(int n,int x) // How many x in n!
{
    int counter=0;
    int i=1;
    while(pow(x,i)<=n)
    {
        counter += n/pow(x,i);
        i++;
    }

    return counter;
}

int BS(int min)
{
    int low,high,trailingZero,mid,minimum;
    low=0;
    high=1000000005;

    while(low<=high)
    {
        mid=(low+high)/2;
        trailingZero = FactorialNoOf5(mid,5);


        if(trailingZero == min) //Found a N!, but need minimum
        {
            flag=1;
            minimum=mid;
            high=mid-1;

        }

        else if(trailingZero > min )
            high = mid-1;

        else
            low = mid+1;

    }

    return minimum;

}
