#include<bits/stdc++.h>
using namespace std;
bool a[5][14]={0};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    if(n==1){
        cout<<51;
        return 0;
    }
    int ans=0;
    char t,x;
    int h=0,d=0;
    for(int i=1;i<=n;++i){
        cin>>t>>x;
        if(t=='C') h=1;
        if(t=='S') h=2;
        if(t=='H') h=3;
        if(t=='D') h=4;
        if(x<='9') d=x-'0';
        if(x=='T') d=10;
        if(x=='J') d=11;
        if(x=='Q') d=12;
        if(x=='K') d=13;
        if(!a[h][d]){
            a[h][d]=1;
        }
    }
    for(int i=1;i<=4;++i){
        for(int j=1;j<=13;++j){
            if(!a[i][j]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
