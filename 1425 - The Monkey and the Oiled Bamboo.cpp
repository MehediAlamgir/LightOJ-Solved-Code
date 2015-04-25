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
#define SIZ 100005

/*====================================== CONSTANT End===================================================*/

int arr[SIZ],n;

int BS();
bool isTrue(int);

int main()
{
    int tc,cn;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>n;
        arr[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }

        int res = BS();
        cout<<"Case "<<cn<<": "<<res<<endl;
    }

	return 0;
}

bool isTrue(int mid)
{
    for(int i=0;i<n;i++)
    {
        int diff = arr[i+1]-arr[i];

        if(diff==mid)
            mid--;

        else if(diff<mid)
            continue;

        else if(diff>mid)
            return false;
    }

    return true;
}

int BS()
{
    int low=0,high=10000005,mid;
    mid=(low+high)/2;

    while(low<=high)
    {
        if(low==high)
            return low;

        else if(isTrue(mid))
            high=mid;

        else
            low=mid+1;

         mid=(low+high)/2;

    }

}
