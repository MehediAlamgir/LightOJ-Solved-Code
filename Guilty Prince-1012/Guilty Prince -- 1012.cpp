#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;

#define input freopen("in.txt","r",stdin)

const int MAX=25;

char board[MAX][MAX];
int vis[MAX][MAX];



int main()
{
    //input;
    int tc,cn,R,C,p,q,cnt=0,i,j;

    scanf("%d",&tc);

    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d%d",&C,&R);

        for(i=0;i<R;i++)
            scanf("%s",board[i]);

        queue<int>Q;

        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
                vis[i][j]=0;

        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            {
                if(board[i][j]=='@')
                {
                    vis[i][j]=1;
                    Q.push(i);
                    Q.push(j);
                }
            }

        while(!Q.empty())
        {
            i=Q.front();
            Q.pop();

            j=Q.front();
            Q.pop();

            p=i-1;
            q=j;

            if(p>=0 && p<R && q>=0 && q<C && board[p][q]=='.')
            {
                if(vis[p][q]==0)
                {
                    vis[p][q]=1;

                    Q.push(p);
                    Q.push(q);
                }
            }

            p=i+1;
            q=j;

            if(p>=0 && p<R && q>=0 && q<C && board[p][q]=='.')
            {

                if(vis[p][q]==0)
                {
                    vis[p][q]=1;

                    Q.push(p);
                    Q.push(q);
                }
            }

            p=i;
            q=j+1;

            if(p>=0 && p<R && q>=0 && q<C && board[p][q]=='.')
            {

                if(vis[p][q]==0)
                {
                    vis[p][q]=1;

                    Q.push(p);
                    Q.push(q);
                }
            }

            p=i;
            q=j-1;

            if(p>=0 && p<R && q>=0 && q<C && board[p][q]=='.')
            {

                if(vis[p][q]==0)
                {
                    vis[p][q]=1;

                    Q.push(p);
                    Q.push(q);
                }
            }
        }
        cnt=0;
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            {
                if(vis[i][j]==1)
                cnt++;
            }

            printf("Case %d: %d\n",cn,cnt);

    }
}
