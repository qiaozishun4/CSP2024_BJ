#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,x,y,d;
string s[1001][1001];
int l=1;
void f(int x1,int y1){
if(k==0){
    cout<<l<<endl;
    return;
}
if(d==0){
    if(s[x1][y1+1]=="x"&&y1+1>m){
        k--;
        d=(d+1)%4;
        f(x1,y1);
    }else{
    l++;
    k--;
    f(x1,y1+1);
    }
}
if(d==1){
    if(s[x1+1][y1]=="x"&&x1+1>n){
        k--;
        d=(d+1)%4;
        f(x1,y1);
    }else{
    l++;
    k--;
    f(x1+1,y1);
    }
}
if(d==2){
    if(s[x1][y1-1]=="x"&&y1-1<1){
        k--;
        d=(d+1)%4;
        f(x1,y1);
    }else{
    l++;
    k--;
    f(x1,y1-1);
    }
}
if(d==3){
    if(s[x1-1][y1]=="x"&&x1-1<1){
        k--;
        d=(d+1)%4;
        f(x1,y1);
    }else{
    l++;
    k--;
    f(x1-1,y1);
    }
}
}
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>s[i][j];
            }
        }
        f(x,y);
    }
    return 0;
}
