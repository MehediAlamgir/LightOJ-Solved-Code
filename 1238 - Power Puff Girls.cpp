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
#define pii pair<int,int>
#define mp make_pair

/*======================================= Macro End====================================================*/

/*====================================== CONSTANT Start===================================================*/

#define INF (1<<30) //infinity value
#define PI (2*acos(0.0))
#define EPS 1e-9
#define MOD 10007
#define SIZ 25

/*====================================== CONSTANT End===================================================*/

char graph[SIZ][SIZ];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int row,col;

int d[SIZ][SIZ],vis[SIZ][SIZ]; //d means destination from source.
int level[SIZ][SIZ];


int bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	level[sx][sy]=0;

	queue<pii>q; //A queue containing STL pairs
	//q.push(pii(sx,sy));
	q.push(mp(sx,sy));

	while(!q.empty())
	{
		pii top=q.front();
		q.pop();

		int u=top.first;
		int v=top.second;

		for(int k=0;k<4;k++)
		{
			int tx=u+dx[k];
			int ty=v+dy[k]; //Neighbor cell [tx][ty]

			if(tx>=0 && tx<row && ty>=0 && ty<col && graph[tx][ty]!='#' && graph[tx][ty]!='m' && vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
			{
				vis[tx][ty]=1;
				level[tx][ty]=level[u][v]+1;
				q.push(mp(tx,ty)); //Pushing a new pair in the queue
				//q.push(pii(tx,ty)); //Pushing a new pair in the queue

				 if(graph[tx][ty]=='h')
                    return level[tx][ty];
			}
		}
	}

}

int main()
{
   // input;
	int tc,cn,sourceRow,sourceCol;
	queue<int>que;

	cin>>tc;
	for(cn=1;cn<=tc;cn++)
    {
        cin>>row>>col;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>graph[i][j];
                if(graph[i][j]=='a' || graph[i][j]=='b' || graph[i][j]=='c')
                {
                   que.push(i);
                   que.push(j);
                }
            }
        }
        int mx=0;
        while(!que.empty())
        {
           int u=que.front();
           que.pop();

           int v=que.front();
           que.pop();

           int c1 = bfs(u,v);
           if(c1>mx)
            mx=c1;
        }


        cout<<"Case "<<cn<<": "<<mx<<endl;
    }

	return 0;
}
