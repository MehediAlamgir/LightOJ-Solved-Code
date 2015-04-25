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
#define PI (2*acos(0.0))
#define EPS 1e-9
#define MOD 10007
#define SIZ 20005

/*====================================== CONSTANT End===================================================*/

vector<int>graph[SIZ];
int color[SIZ],visited[SIZ]; //color 1-->vampire  && color 2-->lykan
int lykan,vampire;

void bfs(int node);


int main()
{
    //input;
    int tc,cn,u,v,n,ly,maximum;
    map<int,int>node;
    set<int>value;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>n;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);

            if(!value.count(u))
                node[cnt++]=u;
            if(!value.count(v))
                node[cnt++]=v;

            value.insert(u);
            value.insert(v);
        }

        int length = node.size();
        maximum=0;
        for(int i=0;i<length;i++)
        {
            lykan=vampire=0;

            int vertex=node[i];

            if(!visited[vertex])
            {
                bfs(vertex);
                int m=max(lykan,vampire);
                maximum += max(lykan,vampire);

            }
        }

        cout<<"Case "<<cn<<": "<<maximum<<endl;

        memset(color,0,sizeof color);
        memset(visited,0,sizeof visited);
        memset(graph,0,sizeof graph);
        value.clear();
        node.clear();
    }


	return 0;
}

void bfs(int node)
{
    queue<int>q;
    q.push(node);
    color[node]=1;
    vampire++;
    visited[node]=1;

    while(!q.empty())
    {
        int u=q.front();
        int length = graph[u].size();
        for(int i=0;i<length;i++)
        {
            int v = graph[u][i];
            if(!visited[v])
            {
                q.push(v);
                if(color[u]==1) //vampire
                {
                    color[v]=2;
                    visited[v]=1;
                    lykan++;
                }
                else if(color[u]==2) //lykan
                {
                    color[v]=1;
                    visited[v]=1;
                    vampire++;
                }
            }
        }

        q.pop();
    }
}
