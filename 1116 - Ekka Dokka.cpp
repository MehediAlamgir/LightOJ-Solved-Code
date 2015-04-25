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
#define SIZ 1000005

/*====================================== CONSTANT End===================================================*/

int List[SIZ];
int counter;
vector<long long>EvenFactor;
vector<long long>OddFactor;

//void primeFactorize(long long);

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc,cn;
    long long num,even,odd,temp,res;

    cin>>tc;

    for(cn=1;cn<=tc;cn++)
    {
        cin>>num;

        temp=1;

        if(num%2==0)
        {
            while(num%2 ==0 )
            {
                num /=2;
                temp *= 2;
            }

            cout<<"Case "<<cn<<": "<<num<<" "<<temp<<endl;
        }

        else
             cout<<"Case "<<cn<<": "<<"Impossible"<<endl;
    }


    return 0;
}

