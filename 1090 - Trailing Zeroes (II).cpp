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

int totalNoOf_NCR5,totalNoOf_NCR2,factorOf_PQ5,factorOf_PQ2;

int FactorialNof(int n,int x)
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

int nof(int n,int x)
{
    int cnt=0;
    while(n%x==0)
    {
        cnt++;
        n /= x;
    }

    return cnt;
}

void nCr(int n,int r)
{
    int nFACTORIAL5 = FactorialNof(n,5);
    int rFACTORIAL5 = FactorialNof(r,5);
    int n_rFACTORIAL5 = FactorialNof(n-r,5);

    int nFACTORIAL2 = FactorialNof(n,2);
    int rFACTORIAL2 = FactorialNof(r,2);
    int n_rFACTORIAL2 = FactorialNof(n-r,2);

     totalNoOf_NCR5 = nFACTORIAL5-rFACTORIAL5-n_rFACTORIAL5;
     totalNoOf_NCR2 = nFACTORIAL2-rFACTORIAL2-n_rFACTORIAL2;

   // return totalNoOf5;
}

void pq(int p,int q)
{
     factorOf_PQ5 = nof(p,5);
     factorOf_PQ2 = nof(p,2);
   // return factorOf5*q;
}

int main()
{
   ios_base::sync_with_stdio(0);
  // input;

   int tc,cn,n,r,p,q;
   cin>>tc;

   for(cn=1;cn<=tc;cn++)
   {
       cin>>n>>r>>p>>q;
       nCr(n,r);
       pq(p,q);

       int TrailingZero = min(totalNoOf_NCR2 + (factorOf_PQ2*q), totalNoOf_NCR5+(factorOf_PQ5*q));

       cout<<"Case "<<cn<<": "<<TrailingZero<<endl;

       totalNoOf_NCR2=factorOf_PQ2=totalNoOf_NCR5=factorOf_PQ2=0;
   }


    return 0;
}
