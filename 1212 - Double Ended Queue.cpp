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

#define inf (1<<30) //infinity value
#define eps 1e-9
#define mod 10007
#define siz 1005

/*====================================== CONSTANT End===================================================*/

int main()
{
   // input;

    int tc,n,m,cn,num;
    string cmd;
    deque<int>dq;

    scanf("%d",&tc);
    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d %d",&n,&m);
       // dq.assign(n);
        printf("Case %d:\n",cn);

        for(int i=0;i<m;i++)
        {
            cin>>cmd;
            if(cmd=="pushLeft")
            {
                scanf("%d",&num);

                if(dq.size()==n)
                {
                    printf("The queue is full\n");
                }

                else
                {
                    dq.push_front(num);
                    printf("Pushed in left: %d\n",num);
                }

            }

            else if(cmd=="pushRight")
            {
                scanf("%d",&num);

                if(dq.size()==n)
                {
                    printf("The queue is full\n");
                }

                else
                {
                    dq.push_back(num);
                    printf("Pushed in right: %d\n",num);
                }

            }

            else if(cmd=="popLeft")
            {

                if(dq.empty())
                {
                    printf("The queue is empty\n");
                }

                else
                {

                    printf("Popped from left: %d\n",dq.front());
                    dq.pop_front();
                }

            }

            else if(cmd=="popRight")
            {

                if(dq.empty())
                {
                    printf("The queue is empty\n");
                }

                else
                {
                    printf("Popped from right: %d\n",dq.back());
                    dq.pop_back();
                }

            }
        }

        while(!dq.empty())
            dq.pop_back();
    }

    return 0;
}
