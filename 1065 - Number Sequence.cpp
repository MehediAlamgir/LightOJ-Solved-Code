#include<bits/stdc++.h>

using namespace std;

long long mod = 1;

struct matrix
{
  long long m[2][2];
};

matrix multiply(matrix a, matrix b)
{

  matrix c;
  for(int i=0;i<2;i++)
  {
      for(int j=0;j<2;j++)
      {
          c.m[i][j]=0;
          for(int k=0;k<2;k++)
          {
              c.m[i][j] += a.m[i][k] * b.m[k][j];
               c.m[i][j] %= mod;
          }
      }
  }

  return c;

}

matrix power(matrix mat, long long p)
{

    if (p == 1)
        return mat;
    if(p&1)
    {
        return multiply(mat,power(mat,p-1));
    }
    else
    {
        matrix ret = power(mat,p/2);
        return multiply(ret,ret);
    }

}

int main()
{
   // freopen("in.txt","r",stdin);
    int tcase;
  long long a,b, n, m,num,cn=0;

  cin >> tcase;
  while (tcase--)
  {
      cin >> a >> b >> n >> m;

        for(int l=0;l<m;l++)
        {
            mod *= 10;
        }

        matrix bm,dm,A,ans;

        bm.m[0][0]=1;
        bm.m[0][1]=1;
        bm.m[1][0]=1;
        bm.m[1][1]=0;


        A.m[0][0]=b;
        A.m[1][0]=a;


        if (n == 0)
        {
            cout<<a%mod<<endl;
        }
        else if(n == 1)
        {
           cout<<b%mod<<endl;
        }
        else
       {
              dm = power(bm, n - 1);
              ans = multiply(dm,A) ;

              cout<<"Case "<<++cn<<": "<<ans.m[0][0] % mod << endl;

        }

        mod=1;
  }
  return 0;
}
