#include <bits/stdc++.h>
using namespace std;
int s[12]={6,2,5,5,4,5,6,3,7,6};
long long int f[100005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    scanf("%d",&t);
    f[0]=0,f[1]=0,f[2]=1,f[3]=7;
    for(int i=4;i<=100000;i++)
    {f[i]=f[i-2]*10+1;
     for(int j=0;j<=9;j++)
     {if(i==6&&j==0)
      {
       continue;
      }
      if(i==s[j]||i>s[j]+1)
      {
       f[i]=min(f[i],f[i-s[j]]*10+j);
      }
     }
    }
    for(int i=1;i<=t;i++)
    {scanf("%d",&n);
     if(n==1)
     {
      printf("-1");
     }
     else
     {
      printf("%lld",f[n]);
     }
    }
    return 0;
}