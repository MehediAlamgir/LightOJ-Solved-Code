#include<stdio.h>
#include<math.h>

int main()
{
    double r,result;
    int tc,cn;

    scanf("%d",&tc);

    for(cn=1;cn<=tc;cn++)
    {
        scanf("%lf",&r);

        result = (4*r*r - (2*acos(0.0)*r*r));

        printf("Case %d: %.2f\n",cn,result+10e-9);
    }

    return 0;
}
