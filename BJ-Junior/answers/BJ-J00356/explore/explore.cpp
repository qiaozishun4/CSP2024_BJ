#include<bits/stdc++.h>
using namespace std;
int c[5];
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int a,n,m,k,x,y,d;
cin>>a;
for(int i=0;i<a;i++){
        c[i]=c[i]+1;
    cin>>n>>m>>k;
    cin>>x>>y>>d;
    struct s;
    for(int z=0;z<=x;z++){
      for(int j=0;j<=y;j++){
       cin>>s;
    }
    }
for(int h=1;h<=k;h++){
    if(d==0){
       if(s[x][y+1]=='.'&&y+1<m){
        y=y+1;
        c[i]=c[i]+1;
    }else {
        d=d+1;
    c[i]=c[i]+1;
    }
    }
     if(d==1){
       if(s[x+1][y]=='.'&&x+1<n){
        x=x+1;
        c[i]=c[i]+1;
    }else {
        d=d+1;
    c[i]=c[i]+1;
    }
    }
    if(d==2){
       if(s[x][y-1]=='.'&&y-1>m){
        y=y-1;
        c[i]=c[i]+1;
    }else {
        d=d+1;
    c[i]=c[i]+1;
    }
    }
    if(d==3){
       if(s[x-1][y]=='.'&&x-1>n){
        x=x-1;
        c[i]=c[i]+1;
    }else {
        d=d-3;
    c[i]=c[i]+1;
    }
    }
}
}
for(int i=0;i<a;i++){
    cout<<c[i];
}
fclose(stdion)
fclose(stdout);
return 0;
}
