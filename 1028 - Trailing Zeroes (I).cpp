/*
    Solution: No. of Divisor

*/


#include<bits/stdc++.h>

using namespace std;

#define SIZ 1000005

long long num=1000005;
int status[SIZ],prime[SIZ],listSize;



void sieve()
{
    int i,j,sqrtN;
    for(int i=2;i<=num;i++)
        status[i] = 0;

    sqrtN = sqrt(num);

    for(i=3;i<=sqrtN;i+= 2)
    {
        if(status[i]==0)
        {
            for(j=i*i;j<=num;j += i+i)
            {
                status[j] = 1;
            }
        }

    }

    int cnt=0;
    prime[cnt++] = 2;

    for(i=3;i<=num;i+=2)
    {
        if(status[i]==0)
           // cout<<i<<" ";
            prime[cnt++] = i;
    }


}

long long primeFactor(long long num1)
{

    int sq = sqrt(num1);
    int div = 1;

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

int main()
{
    sieve();
    int tc,cn;
    long long num2;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>num2;
        int res = primeFactor(num2);
        cout<<"Case "<<cn<<": "<<res-1<<endl;   // -1 is needed to exclude divisor 1 as there is no base of 1.
    }
}
