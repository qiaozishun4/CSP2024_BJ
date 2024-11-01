#include<bits/stdc++.h>
bool vis[5][15];
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string c;
        cin>>c;
        int tp=0,num=0;
        if(c[0]=='D'){
            tp=1;
        }
        if(c[0]=='C'){
            tp=2;
        }
        if(c[0]=='H'){
            tp=3;
        }
        if(c[0]=='S'){
            tp=4;
        }
        if(c[1]>='0'&&c[1]<='9'){
            num=c[1]-'0';
        }
        else{
            if(c[1]=='A'){
                num=1;
            }
            if(c[1]=='T'){
                num=10;
            }
            if(c[1]=='J'){
                num=11;
            }
            if(c[1]=='Q'){
                num=12;
            }
            if(c[1]=='K'){
                num=13;
            }
        }
        vis[tp][num]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(vis[i][j]==0){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
