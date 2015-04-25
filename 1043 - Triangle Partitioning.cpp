/*
Technique: Binary Search
Firstly , we assume a value of AD. Then we calculate ratio of ADE and BDEC(ADE/BDEC) according to our assumed value. Then we compare
new calculated ratio with given ratio. To find value of AE and DE we use property of "similar triangle".Similar Triangle property is
(AD/AB) = (AE/AC) = (DE/BC).As ans have to  correct upto 10^-6 fraction value, we can't say mid+1 OR mid-1 for high and low value
because fraction value can be between 0.0 to 0.99(That means between 1).That's why we cant increase or decrease directy 1 from mid value
of high and low.

*/


#include<bits/stdc++.h>

using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

double BS(double,double,double,double);
double triangleRatio(double,double,double,double);

int main()
{
    int tc,cn;
    double ab,ac,bc,ratio,ans;
    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>ab>>ac>>bc>>ratio;
        ans= BS(ab,ac,bc,ratio);
        cout<<"Case "<<cn<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }

}

double triangleRatio(double ab,double ac,double bc,double ad)
{
    double ae,de,s1,s2,largeTriangleArea,smallTriangleArea,trapheziumArea, ratio;
    ae = (ad*ac)/ab;
    de = (ad*bc)/ab;

    s1 = (ab+ac+bc)/2.0;
    s2 = (ad+ae+de)/2.0;
    largeTriangleArea = sqrt(s1 * (s1-ab) * (s1-ac) * (s1-bc));
    smallTriangleArea = sqrt(s2 * (s2-ad) * (s2-ae) * (s2-de));
    trapheziumArea = largeTriangleArea - smallTriangleArea;

    ratio  = smallTriangleArea/trapheziumArea;
    return ratio;
}

double BS(double ab,double ac,double bc,double ratio)
{
    double low,high,ad,mid;
    low=0.0;
    high = ab;

    for(int i=0;i<100;i++) // 32 iteration will find the answer. But we need to correct till 10^-6 . So for making sure we did 100 iteration
    {
        mid = (low+high)/2.0;
        ad = mid;

        if(triangleRatio(ab,ac,bc,ad)>ratio)
            high=mid;

        else
            low=mid;
    }

    return ad;

}
