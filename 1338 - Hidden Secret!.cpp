/*
Solution:

Firstly remove all the whitespace from the 2 strings  then make all the character
of 2 strings lowercase.After that , check all the character of 1st string with all
the character of 2nd string, if q index character of 2nd string matches with p
index character, then remove the q index character from 2nd string. if any 1st string
character doesn't matches with 2nd string character then we can easily say that all the
character of given 2 string are not same. so we do break from this position and show
the output. if the no of character in 2nd string  matches the size of the 2nd string
then we can say "Yes".



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

  //  input;

    int tc,cn;
    string str1,str2,LOWER1,LOWER2;
    locale loc;

    cin>>tc;
    getline(cin,str1);
    for(cn=1;cn<=tc;cn++)
    {
       // cin>>str1>>str2;
       getline(cin,str1);
       getline(cin,str2);

        LOWER1="";
        LOWER2="";

            int sz3 = str1.length();
            int sz4 = str2.length();

            for(int i=0;i<sz3;i++ )
            {
                if(str1[i]==' ')
                    continue;

                else
                    LOWER1 += tolower(str1[i],loc);

            }

            for(int i=0;i<sz4;i++ )
            {
                if(str2[i]==' ')
                    continue;
                else
                    LOWER2 += tolower(str2[i],loc);
            }

            int sz5 = LOWER1.length();
            int sz6 = LOWER2.length();
            int cnt=0;

            bool f =false;

            for(int p=0;p<sz5;p++)
            {
                for(int q=0;q<sz6;q++)
                {
                    if(LOWER1[p]==LOWER2[q])
                    {
                        f=true;
                        cnt++;
                        LOWER2.erase(LOWER2.begin()+q); // Remove qth character from LOWER2 to avoid duplicate character problem.
                        break;

                    }
                }

                if(f==false)
                {
                    break;
                }
            }

            if(cnt==sz6)
            {
                cout<<"Case "<<cn<<": "<<"Yes"<<endl;
            }

            else
                cout<<"Case "<<cn<<": "<<"No"<<endl;

    }

    return 0;
}
