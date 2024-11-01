#include<bits/stdc++.h>
using namespace std;
bool v[105][105];long long n=0,ans=0;char c[4];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c;
        bool fn=0;long long x=0,y=0;
        if(c[1]=='A'){
            fn=1;
            y=1;
        }
        if(c[1]=='T'){
            fn=1;
            y=10;
        }
        if(c[1]=='J'){
            fn=1;
            y=11;
        }
        if(c[1]=='Q'){
            fn=1;
            y=12;
        }
        if(c[1]=='K'){
            fn=1;
            y=13;
        }
        if(!fn){
            y=c[1]-'0';
        }
        if(c[0]=='D')x=1;
        if(c[0]=='C')x=2;
        if(c[0]=='H')x=3;
        if(c[0]=='S')x=4;
        v[x][y]=1;


    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(v[i][j]==0)ans++;
        }
    }
    cout<<ans;
    return 0;


}
