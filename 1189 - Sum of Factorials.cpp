/*
Solution: It is possible to use a greedy approach: since fact(n) > fact(0)+fact(1)+...+fact(n-1)
(this is true for each n > 2) you can iterate from the greatest factorial(20!) to the smallest one,
if fact[i] is less than or equal to N you must take it, decrease N by fact[i] and proceed with the
next factorial. At the end, if N is 0 you found the solution, otherwise it is impossible to obtain
N adding factorials

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
#define SIZ 25

/*====================================== CONSTANT End===================================================*/

long long fact[SIZ];

void precal()
{
    int n;

    fact[0]=1;
    fact[1]=1;
    for(int i=2;i<=21;i++)
    {
        fact[i] = fact[i-1]*i;
    }
//
//    for(int j=0;j<25;j++)
//        cout<<"fact["<<j<<"]: "<<fact[j]<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
  //  input;
    precal();

    int tc,cn;
    long long n;
    set<int>s;
    bool flag;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        flag=0;
        s.clear();
        cin>>n;
        for(int i=20;i>=0;i--)
        {
            if(fact[i]<=n)
            {
                s.insert(i);
                n -= fact[i];
                if(n==0)
                {
                    flag=1;
                    break;
                }
            }

        }

        if(flag==1)
        {
            cout<<"Case "<<cn<<": ";
            while(!s.empty())
            {
                if(s.size()>1)
                    cout<<*s.begin()<<"!+";
                else
                    cout<<*s.begin()<<"!";
                s.erase(s.begin());

//                if(s.size() >=1 )
//                    cout<<"+";
            }

            cout<<'\n';
        }

        else
            cout<<"Case "<<cn<<": impossible"<<endl;

    }

    return 0;
}
