/*
Technique: Binary Search
Here first we assume a value. Then we calculate a new value of c for assumed value. In BS function we compare our new value of c with
given value of c. As ans have to correct upto 10^-6 fraction value, we can't say mid+1 OR mid-1 for high and low value because fraction
value can be between 0.0 to 0.99(That means between 1). That's why we cant increase or decrease directy 1 from mid value of high and low.

Calculation:Property of similar triangle( Widespace Notebook(first page) )

*/

#include<bits/stdc++.h>

using namespace std;

#define MIN(a,b) (a<b?a:b)

double BS(double,double,double);

int main()
{
    int tc,cn;
    double x,y,c,ans;
    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>x>>y>>c;
        ans=BS(x,y,c);
        cout<<"Case "<<cn<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }
}

double BS(double x,double y,double c)
{
    double low,high,c1,ac,bc,af,mid;
    low=0.0;
    high=MIN(x,y); // As both two ladders have to touch opposite building, so  MIN. If we take MAX small ladder will not touch opposite building


    for(int i=0;i<100;i++)  // 32 iteration will find the answer. But we need to correct till 10^-6 . So for making sure we did 100 iteration
    {

           mid = (high+low)/2;
           ac=mid;

           bc = sqrt( pow(y,2) - pow(ac,2) );
           af = sqrt( pow(x,2) - pow(ac,2) );
           c1 = (bc*af)/(af+bc);

           if(c1>c)
             low=mid;

           else
            high=mid;
    }

    return ac;

}
