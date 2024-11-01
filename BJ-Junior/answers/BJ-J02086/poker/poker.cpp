#include <bits/stdc++.h>
using namespace std;
int po[5][15];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,a,b,cnt=0;
    scanf("%d",&n);
    string s;
    for(int i=1;i<=n;i++)
    {cin>>s;//c,d,h,s
     if(s[0]=='C')
     {
      a=1;
     }
     else if(s[0]=='D')
     {
      a=2;
     }
     else if(s[0]=='H')
     {
      a=3;
     }
     else
     {
      a=4;
     }
     if(s[1]=='A')
     {
      b=1;
     }
     else if(s[1]=='T')
     {
      b=10;
     }
     else if(s[1]=='J')
     {
      b=11;
     }
     else if(s[1]=='Q')
     {
      b=12;
     }
     else if(s[1]=='K')
     {
      b=13;
     }
     else
     {
      b=s[1]-48;
     }
     po[a][b]=1;
    }
    for(int j=1;j<=4;j++)
    {for(int k=1;k<=13;k++)
     {if(po[j][k]==0)
      {
       cnt++;
      }
     }
    }
    printf("%d",cnt);
    return 0;
}
