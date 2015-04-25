/*
Solution:No of Divisor of Total Consumed Piaju.

Read carefully the problem description. The input contains two integers P and L, and the output should be a list of all
possible values for Q. Notice however the restriction L < Q.With that in mind, in the first sample case(10 0 ), it's possible
that 10 people eat 1 piaju each (Q=1), and the remainder is 0 (L=0), but in the second test case(13 2), it is not possible that
the contestants each 1 piaju each, and 2 remain uneaten (Q=1, L=2).
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
#define PI (2*acos(0.0))
#define EPS 1e-9
#define MOD 10007
#define SIZ 50000

/*====================================== CONSTANT End===================================================*/

set<int>List;
set<int>::iterator it;

void divisor(int,int);

int main()
{

    int tc,cn,p,l,totalConsumedPiaju;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>p>>l;
        totalConsumedPiaju=p-l;

        if(totalConsumedPiaju<=l)
            cout<<"Case "<<cn<<": impossible"<<endl;

        else
        {
            List.clear();
            divisor(totalConsumedPiaju,l);

            cout<<"Case "<<cn<<":";
            if(l==0)
            {
                List.insert(1);
                if(totalConsumedPiaju%2==0)
                {
                    List.insert(totalConsumedPiaju);
                }

                for(it=List.begin();it!=List.end();it++)
                     cout<<" "<<*it;

            }

            else
            {
                if(totalConsumedPiaju%2==0)
                {
                    List.insert(totalConsumedPiaju);
                }

                 for(it=List.begin();it!=List.end();it++)
                     cout<<" "<<*it;
            }

            cout<<'\n';
        }
    }

	return 0;
}

void divisor(int num,int from)
{
    int sqrtN=sqrt(num);
    for(int i=1;i<=sqrtN;i++)
    {
        if(num%i==0)
        {
            if(i>from)
                List.insert(i);
            if((num/i) > from)
                List.insert(num/i);
        }
    }

}

