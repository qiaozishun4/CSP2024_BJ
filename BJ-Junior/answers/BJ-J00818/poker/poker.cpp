#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    char a_,b_;
    int a,b;
}x[110];
bool f[110][110];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>x[i].a_>>x[i].b_;
        if(x[i].a_=='D'){
            x[i].a=1;
        }else if(x[i].a_=='C'){
            x[i].a=2;
        }else if(x[i].a_=='H'){
            x[i].a=3;
        }else{
            x[i].a=4;
        }
        if(x[i].b_=='T') x[i].b=10;
        else if(x[i].b_=='A') x[i].b=1;
        else if(x[i].b_=='J') x[i].b=11;
        else if(x[i].b_=='Q') x[i].b=12;
        else if(x[i].b_=='K') x[i].b=13;
        else x[i].b=x[i].b_-'0';
        f[x[i].a][x[i].b]=true;
    }
    int ans=0;
    for(int i=1; i<=4; i++){
        for(int j=1; j<=13; j++){
            if(f[i][j]==false) ans++;
        }
    }
    cout<<ans;
    return 0;
}
