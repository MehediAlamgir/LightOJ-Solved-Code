#include<bits/stdc++.h>
using namespace std;

char str[30][30];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c,i,j,k,x,y,a,b,cnt;

//int arr[4][2] = {0 , 1 , 0 , -1 , 1 , 0 , -1 , 0};

 queue<int>q;

int dfs(int gr,int gc)
{
    cnt=1;

    q.push(gr);
    q.push(gc);

    while(!q.empty())
    {
        i=q.front();
        q.pop();

        j=q.front();
        q.pop();

        for(k=0;k<4;k++)
        {
            a=i+dx[k];
            b=j+dy[k];

          //  a = i + arr[k][0];
           // b = j + arr[k][1];

            if(a>=0 && a<r && b>=0 && b<c && str[a][b]=='.')
            {
                q.push(a);
                q.push(b);
                str[a][b]='#';
                cnt++;
            }

        }
    }
  //  printf("%d",cnt);

    return cnt;

}


int main()
{
    //freopen("in.txt","r",stdin);
    int tc,cn,res,row,col;

    scanf("%d",&tc);
    for(cn=1;cn<=tc;cn++)
    {
         scanf("%d %d",&c,&r);

    for(i=0;i<r;i++)
        scanf("%s",str[i]);


    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(str[i][j]=='@')
            {
                row=i;
                col=j;
            }
        }
    }

    res=dfs(row,col);
    printf("Case %d: %d\n",cn,res);
    cnt=0;

    }



}
