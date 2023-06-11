#include <bits/stdc++.h>

void solve1(int n,vector<vector<long long int>> &v)
{

    for (int i = 0; i < n; i++) 
    {
        vector<long long int> temp;
        for(int j= 0; j <= i;j++)
        {
          if(j==0 or j==i)
            temp.push_back(1);
          else
            temp.push_back(v[i-1][j-1] + v[i-1][j]);
        }
        v.push_back(temp);
    }

}
long long int ncr(int n,int r)
{
  long long int res = 1;
  for(int i = 0; i < r ;i++ )
  {
    res = res*(n-i);
    res = res / (i+1);
  }
  return res;
}
void solve2(int n,vector<vector<long long int>> &v)
{
  for(int i = 0; i < n;i++)
  {
    vector<long long int> temp;
    for(int j = 0 ; j <= i;j++)
    { 
      
      temp.push_back(ncr(i,j));
    }
    v.push_back(temp);
  }
}

void solve3(int n,vector<vector<long long int>> &v)
{
  for(int i = 1; i <= n;i++)
  {
    vector<long long int> temp;
    long long ans = 1;
    for(int j = 0 ; j < i;j++)
    { 
      if(j==0 or j==i) ans = 1;
      else 
      {
        ans = ans * (i-j);
        ans = ans / j;
      }
      temp.push_back(ans);
    }
    v.push_back(temp);
  }
}
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> v;
    solve3(n, v);
    return v;
}
