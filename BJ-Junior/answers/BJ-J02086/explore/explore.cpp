#include <bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,n,m,k,x1,y1,cnt;
    int x,y,d;
    scanf("%d",&t);
    string s;
    for(int i=1;i<=t;i++)
    {cnt=0;
     scanf("%d %d %d",&n,&m,&k);
     scanf("%d %d %d",&x,&y,&d);
     for(int j=1;j<=n;j++)
     {
      cin>>s;
      for(int l=0;l<m;l++)
      {if(s[l]=='x')
       {
        a[j][l+1]=0;
       }
       else
       {
        a[j][l+1]=1;
       }
      }
     }
     a[x][y]=2;
     while(k>0)
     {x1=x,y1=y;
      if(d==0)
      {
       y1++;
      }
      else if(d==1)
      {
       x1++;
      }
      else if(d==2)
      {
       y1--;
      }
      else
      {
       x1--;
      }
      if(x1>=1 && x1<=n && y1>=1 && y1<=m && a[x1][y1])
      {
       x=x1,y=y1;
       a[x][y]=2;
      }
      else
      {
       d=(d+1)%4;
      }
      k--;
     }
     for(int o=1;o<=n;o++)
     {for(int p=1;p<=m;p++)
      {if(a[o][p]==2)
       {
        cnt++;
       }
      }
     }
     printf("%d\n",cnt);
    }
    return 0;
}