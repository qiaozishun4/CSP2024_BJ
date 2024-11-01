#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n;
string s[N];
bool vis[5][20]={};
int cnt=0;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        if(s[i][0]=='D'){
            if(s[i][1]=='A') vis[1][1]=true;
            else if(s[i][1]=='T') vis[1][10]=true;
            else if(s[i][1]=='J') vis[1][11]=true;
            else if(s[i][1]=='Q') vis[1][12]=true;
            else if(s[i][1]=='K') vis[1][13]=true;
            else vis[1][s[i][1]-'0']=true;
        }
        else if(s[i][0]=='C'){
            if(s[i][1]=='A') vis[2][1]=true;
            else if(s[i][1]=='T') vis[2][10]=true;
            else if(s[i][1]=='J') vis[2][11]=true;
            else if(s[i][1]=='Q') vis[2][12]=true;
            else if(s[i][1]=='K') vis[2][13]=true;
            else vis[2][s[i][1]-'0']=true;
        }
        else if(s[i][0]=='H'){
            if(s[i][1]=='A') vis[3][1]=true;
            else if(s[i][1]=='T') vis[3][10]=true;
            else if(s[i][1]=='J') vis[3][11]=true;
            else if(s[i][1]=='Q') vis[3][12]=true;
            else if(s[i][1]=='K') vis[3][13]=true;
            else vis[3][s[i][1]-'0']=true;
        }
        else{
            if(s[i][1]=='A') vis[4][1]=true;
            else if(s[i][1]=='T') vis[4][10]=true;
            else if(s[i][1]=='J') vis[4][11]=true;
            else if(s[i][1]=='Q') vis[4][12]=true;
            else if(s[i][1]=='K') vis[4][13]=true;
            else vis[4][s[i][1]-'0']=true;
        }
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!vis[i][j]){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}

