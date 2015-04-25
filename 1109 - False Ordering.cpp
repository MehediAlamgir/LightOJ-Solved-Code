/*
Solution: Find number of divisor of 1 to 1000 using pre calculation and save the result in a array. Then sort the array according to given 2 condition.
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
#define SIZ 1000

/*====================================== CONSTANT End===================================================*/

int prime[SIZ],status[SIZ],divisor[SIZ],listSize;
map<int,int>mp;

void sieve();
int divisorCount(int n);

struct data
{
    int num,NumOFdivisor;
}order[SIZ];

bool compare(data a, data b)
{
    if(a.NumOFdivisor<b.NumOFdivisor)
        return true;
    if( (a.NumOFdivisor==b.NumOFdivisor) && (a.num>b.num) )
        return true;

    return false;

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    sieve();

    for(int i=1;i<=1000;i++)
    {
        order[i].num = i;
        order[i].NumOFdivisor = divisorCount(i);
    }

    sort(order+1,order+1001,compare); //If you want to sort a array from index 3(0 based) to 10 then you have to write "sort( array+3, array+11 )" .This array index start from 1 .

    int tc,cn,n;
    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>n;
        cout<<"Case "<<cn<<": "<<order[n].num<<endl;
    }

    return 0;
}

void sieve()
{
    int sqrtN;
    for(int i=2;i<=SIZ;i++)
        status[i]=0;

    sqrtN = int(sqrt((double) SIZ ));

    for(int i=3;i<=sqrtN;i+=2)
    {
        if(status[i]==0)
        {
            for(int j=i*i;j<=SIZ;j += i+i)
                status[j]=1;
        }
    }

    int cnt=0;
    prime[cnt++]=2;

    for(int i=3;i<=SIZ;i+=2)
    {
        if(status[i]==0)
          //  cout<<i<<endl;
            prime[cnt++]=i;
    }
}

int divisorCount(int num1)
{

        int div = 1;
        //int num1 = number;
        int sq = sqrt(num1);

        for(int i=0;prime[i]<=sq;i++)
        {
            if(num1 % prime[i]==0)
            {
                 listSize=0;

                while(num1%prime[i]==0)
                {
                    num1 /= prime[i];
                    listSize++;
                }
                div *= (listSize+1);    // Counting number of divisor
                sq = sqrt(num1);      // optimization by updating sqrtN, because n is decreased.
            }
        }

        if(num1>1)
        {
            div *= 2;
            listSize++;
        }


    return div;
}
