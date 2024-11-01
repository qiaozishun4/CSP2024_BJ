#include<bits/stdc++.h>
using namespace std;
char a[1005][1005];
int b[1005][1005]={0};
int n,m,k;
int panduan(int x,int y){
  if(((x>n||y>m)||x<1)||y<1) return 0;
  if(a[x][y]=='x') return 0;
  return x*10000+y;
}
int main(){
  freopen("explore.in","r",stdin);
  freopen("explore.out","w",stdout);
  int T;
  cin>>T;
  for(int i=0;i<T;i++){
    cin>>n>>m>>k;
    int x,y,d,cnt=0;
    cin>>x>>y>>d;
    for(int j=1;j<=n;j++){
      for(int k=1;k<=m;k++){
        cin>>a[j][k];
        b[j][k]=0;
      }
    }
    for(int j=1;j<=k;j++){
      b[x][y]=1;
      int condition;
      if(d==0) condition=panduan(x,y+1);
      else if(d==1) condition=panduan(x+1,y);
      else if(d==2) condition=panduan(x,y-1);
      else condition=panduan(x-1,y);
      if(condition==0) d=(d+1)%4;
      else{
        x=condition/10000;
        y=condition%10000;
      }
      b[x][y]=1;
    }
    for(int j=1;j<=n;j++){
      for(int k=1;k<=m;k++){
        if(b[j][k]!=0) cnt++;
      }
    }
    cout<<cnt<<endl;
  }
  return 0;
}
