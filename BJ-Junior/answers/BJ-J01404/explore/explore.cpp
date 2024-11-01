#include<iostream>
#include<vector>
using namespace std;

int main()
{
  freopen("explore.in","r",stdin);
  freopen("explore.out","w",stdout);
  int t;
  cin>>t;
  for(int ii=0;ii<t;ii++)
  {
    int n,m,k,x,y,d,num=1;
    cin>>n>>m>>k>>x>>y>>d;
    vector<string>a(n);
    for(int i=0;i<n;i++)
      cin>>a[i];
    a[x-1][y-1]=0;
    for(int i=0;i<k;i++)
    {
      if(d==0&&y+1<=m&&a[x-1][y]!='x')
      {
        if(a[x-1][y]!=0)
          num++;
        a[x-1][y]=0;
        y++;
        continue;
      }
      else if(d==0)
      {
        d=(d+1)%4;
        continue;
      }
      
      if(d==1&&x+1<=n&&a[x][y-1]!='x')
      {
        if(a[x][y-1]!=0)
          num++;
        a[x][y-1]=0;
        x++;
        continue;
      }
      else if(d==1)
      {
        d=(d+1)%4;
        continue;
      }
      
      if(d==2&&y-1>=1&&a[x-1][y-2]!='x')
      {
        if(a[x-1][y-2]!=0)
          num++;
        a[x-1][y-2]=0;
        y--;
        continue;
      }
      else if(d==2)
      {
        d=(d+1)%4;
        continue;
      }
      
      if(d==3&&x-1>=1&&a[x-2][y-1]!='x')
      {
        if(a[x-2][y-1]!=0)
          num++;
        a[x-2][y-1]=0;
        x--;
        continue;
      }
      else if(d==3)
      {
        d=(d+1)%4;
        continue;
      }
    }
    cout<<num<<endl;
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}