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
    //input;
    //output;

    int tc,cn;
    string command,url,cp;
    stack<string>f,b;

    scanf("%d",&tc);
    for(int cn=1;cn<=tc;cn++)
    {
        printf("Case %d:\n",cn);

        url="http://www.lightoj.com/";

        while(cin>>command)
        {
            if(command=="VISIT")
            {
                b.push(url);
               // getline(cin,url);
                cin>>url;
                cout<<url<<'\n';
                //printf("%s\n",url.c_str());

                while (!f.empty())
                {
                    f.pop();
                }
            }

            else  if(command=="BACK")
            {
                if(b.empty())
                {
                    cout<<"Ignored"<<'\n';
                }

                else
                {
                    f.push(url);
                    cp=b.top();
                    url=cp;
                    cout<<cp<<'\n';
                    // printf("%s\n",cp.c_str());
                    b.pop();

                }

            }

            else  if(command=="FORWARD")
            {
                if(f.empty())
                {
                    cout<<"Ignored"<<'\n';
                }

                else
                {
                    b.push(url);
                    cp=f.top();
                    url=cp;
                    cout<<cp<<'\n';
                    // printf("%s\n",cp.c_str());
                    f.pop();
                }

            }

            else  if(command=="QUIT")
            {
                while(!b.empty())
                {
                    b.pop();
                }

                while(!f.empty())
                {
                    f.pop();
                }
                break;
            }
        }
    }




    return 0;
}
