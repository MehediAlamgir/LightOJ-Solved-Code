/*
Solution: Shaded Region = Area of Triangle - summation of 3 sector

radians = degrees x PI / 180 (deg to rad conversion)
degrees = radians x 180 / PI (rad to deg conversion)

Ref : http://math.stackexchange.com/questions/1169357/how-to-find-the-area-of-blue-shaded-region
Supporting  Link: http://www.mathsrevision.net/gcse-maths-revision/trigonometry/sine-and-cosine-rule
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
#define PI (2*acos(0.0))
#define MOD 10007
#define SIZ 1005

/*====================================== CONSTANT End===================================================*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc,cn;
    double r1,r2,r3,AB,BC,CA,angle1,angle2,angle3,temp,TriangleArea,sector1,sector2,sector3,TotalAreaOF3Sector,ShadedRegion;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>r1>>r2>>r3;
        AB=r1+r2;
        BC=r2+r3;
        CA=r3+r1;

        temp = ( AB*AB + CA*CA - BC*BC ) / (2.0*AB*CA);
        angle1 = acos(temp); //in radian

        temp = (AB*AB + BC*BC - CA*CA) / (2.0*AB*BC);
        angle2 = acos(temp); //in radian

        temp = (CA*CA + BC*BC - AB*AB) / (2.0*CA*BC);
        angle3 = acos(temp);

        sector1 = (r1*r1 * angle1)/2.0; //when angle is in radian. But when angle is in degree then sectorArea = ( (angle/360)*PI*r*r )
        sector2 = (r2*r2 * angle2)/2.0;
        sector3 = (r3*r3 * angle3)/2.0;

        TotalAreaOF3Sector = sector1+sector2+sector3;

        //        TriangleArea = 0.5*CA*AB*(sin(angle1) ); //Here, the angle between AB and CA is angle1.

        double s = (AB+BC+CA)/2;
        TriangleArea = sqrt(s*(s-AB)*(s-BC)*(s-CA)); //Heron's Formula

        ShadedRegion = TriangleArea-TotalAreaOF3Sector;

        cout<<"Case "<<cn<<": "<<fixed<<setprecision(10)<<ShadedRegion+EPS<<endl;

    }

    return 0;
}
