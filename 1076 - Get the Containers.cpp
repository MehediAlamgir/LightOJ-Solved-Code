/*
Algorithm: Binary Search

Maximum vessel size will be initial lower point.Because the minimum answer of any case can be the maximum vessel size.If we take low=0,
then answer can be minimized than maximum capacity vessel, But i have to pour total milk of a particular vessel in a container.
I can't share total milk of a particular vessel in more than 1 container.

Input:
2
6 5
16 37 21 94 58 82
9 8
362030 522667 826235 49575 732626 910298 567963 132824 379329

Output:
Case 1: 94
Case 2: 910298

If i take low=0,Then for the first case, than ans will be 53. But here ans is 94 which is the maximum capacity of vessel.

*/


#include<bits/stdc++.h>

using namespace std;

#define SIZ 1005

bool isPossible(int);
int BS(long long,int);

int n,m,vessel[SIZ];

int main()
{
    int tc,cn,res;
    long long low,total;
    cin>>tc;

    for(cn=1;cn<=tc;cn++)
    {
        cin>>n>>m;
        total=low=0;
        for(int i=0;i<n;i++)
        {
            cin>>vessel[i];

            total += vessel[i];

            if(vessel[i]>low)
                low=vessel[i];
        }

        res = BS(total,low);
        cout<<"Case "<<cn<<": "<<res<<endl;
    }


}

bool isPossible(int capacity)
{
    int temp;
    int cnt = 1;

    temp=0;
    for(int i=0;i<n;i++)
    {
        if( temp+vessel[i] <= capacity )
        {
            temp = temp+vessel[i];
        }
        else    //Filled to brim, new container needed
        {
            temp=vessel[i];
            cnt++;
        }
    }

     if(cnt>m)
        return false;

     else
       return true;

}

int BS(long long total,int maxCapacity)
{
    int low,mid,ans;
    long long high;

    low = maxCapacity;
    high = total;

    while(low<=high)
    {
        mid = (low+high)/2;

        if(isPossible(mid))
        {
             ans = mid;
             high = mid-1;
        }

        else
            low = mid+1;
    }

    return ans;
}
