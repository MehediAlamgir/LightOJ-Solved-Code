#include<bits/stdc++.h>

using namespace std;

long long mod = 10007;

struct matrix
{
  long long m[4][4];
};

matrix multiply(matrix a, matrix b)
{

  matrix c;
  for(int i=0;i<4;i++)
  {
      for(int j=0;j<4;j++)
      {
          c.m[i][j]=0;
          for(int k=0;k<4;k++)
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
  int tcase;
  long long a, b, n, c,cn=1;;

  cin >> tcase;
  while (tcase--)
  {
        cin >> n >> a >> b >> c;


        matrix bm,dm,A,ans;

        bm.m[0][0]=a;
        bm.m[0][1]=0;
        bm.m[0][2]=b;
        bm.m[0][3]=1;
        bm.m[1][0]=1;
        bm.m[1][1]=bm.m[1][2]=bm.m[1][3]=0;
        bm.m[2][1]=1;
        bm.m[2][0]=bm.m[2][2]=bm.m[2][3]=0;
        bm.m[3][3]=1;
        bm.m[3][0]=bm.m[3][1]=bm.m[3][2]=0;

        A.m[0][0]=A.m[1][0]=A.m[2][0]=0;
        A.m[3][0]=c;


        if (n <= 2)
        {
            printf("Case %lld: 0\n",cn++);
        }
        else
        {
              dm = power(bm, n - 2);
              ans = multiply(dm,A) ;

              cout <<"Case "<<cn++<<": "<< ans.m[0][0] << endl;
        }
  }
  return 0;
}
