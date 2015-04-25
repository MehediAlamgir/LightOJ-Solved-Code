/*
Solution:

Check HSC Physics 1st Paper by Shahjahan Topon , Page : 82 , EXM: 8 AND by Gias Uddin, Page : 65,EXM: 2.18 for d
For d, we need the following 2 equation
1. v^2 = u^2 + 2as , u always will be 0
2. Passed distance, s = d-0 , as because at the time of collision distance between two trains is 0, so d-0.

We have to find s1 and s2 from 1st equation for both the train,add them . From the equation 2 we get s==d. so s is our desired d.

For Bird Distance, we have to keep in mind that , it is not sure that,2 train will stop exactly at the same time, one may stop before another train.
so we have to calculate t for both train then we will multiply the highest t with bird constant velocity.

we know a=v/t , so t=v/a
t1 = v1/a1 and t2 = v2/a2 then max(t1,t2) * bird velocity v3 which is our desired distance covered by bird.

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

    int tc,cn;
    double v1,v2,v3,a1,a2,res,s1,s2,s,t1,t2,birdDistance;
    const double u = 0.0;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>v1>>v2>>v3>>a1>>a2;

        s1 = (v1*v1 - u*u)/(2.0*a1);
        s2 = (v2*v2 - u*u)/(2.0*a2);

        s = s1+s2; // As at the time of collision distance is 0. So s = d-0=>s=d

        t1 = v1/a1; // a =(v/t);
        t2 = v2/a2;

        double mx = max(t1,t2);
        birdDistance = mx*v3;

        cout<<"Case "<<cn<<": "<<fixed<<setprecision(9)<<s+EPS<<" "<<fixed<<setprecision(9)<<birdDistance+EPS<<endl;

    }

    return 0;
}
