#include<bits/stdc++.h>

using namespace std;

#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)

#define N 100001

struct node
{
    int sum;

}nd[4*N];

node zero;
node ret;

int idx;

void update_node(int index, int value)
{
    nd[index].sum = value;
}

node merge_node(node a1, node b1)
{
    node ret;
   //ret.sum = a.sum + b.sum;
    ret.sum = min(a1.sum,b1.sum);
    return ret;
}

void update(int idx,int st,int ed, int i, int v)
{
    if(st>i || ed<i)
        return;

    if(st==i && ed==i)
    {
        update_node(idx,v);
        return;
    }

    int mid = (st+ed)/2;
    int left=2*idx;
    int right=2*idx+1;

    update(left,st,mid,i,v);
    update(right,mid+1,ed,i,v);

    nd[idx] = merge_node(nd[left],nd[right]);
}



node query(int idx, int st, int ed, int i, int j)
{
    node a,b;

    if(st>j || ed<i)
        return zero;

    if(st>=i && ed<=j)
        return nd[idx];

    int mid=(st+ed)/2;
    int left=2*idx;
    int right=2*idx+1;

    a=query(left,st,mid,i,j);
    b=query(right,mid+1,ed,i,j);

    return merge_node(a,b);

}


int main()
{
    int tc,cn,n,q,i,j,Nvalue,Qvalue1,Qvalue2;

    scanf("%d",&tc);
    for(cn=1;cn<=tc;cn++)
    {
        scanf("%d %d",&n,&q);

        for(int p=1;p<=n;p++)
        {
            scanf("%d",&Nvalue);
            update(1,1,n,p,Nvalue);
        }
        zero.sum=2147483647;
        printf("Case %d:\n",cn);
        for(int k = 1;k<=q;k++)
        {
            scanf("%d %d",&Qvalue1,&Qvalue2);
            printf("%d\n",query(1,1,n,Qvalue1,Qvalue2));
        }

    }

    return 0;
}
