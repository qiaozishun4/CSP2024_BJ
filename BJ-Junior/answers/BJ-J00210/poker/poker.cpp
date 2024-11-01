#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool vis[5][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='T')   vis[1][10]=1;
            else if(s[1]=='J')  vis[1][11]=1;
            else if(s[1]=='Q')  vis[1][12]=1;
            else if(s[1]=='K')  vis[1][13]=1;
            else if(s[1]=='A')  vis[1][1]=1;
            else    vis[1][s[1]-'0']=1;
        }else if(s[0]=='C'){
            if(s[1]=='T')   vis[2][10]=1;
            else if(s[1]=='J')  vis[2][11]=1;
            else if(s[1]=='Q')  vis[2][12]=1;
            else if(s[1]=='K')  vis[2][13]=1;
            else if(s[1]=='A')  vis[2][1]=1;
            else    vis[2][s[1]-'0']=1;
        }else if(s[0]=='H'){
            if(s[1]=='T')   vis[3][10]=1;
            else if(s[1]=='J')  vis[3][11]=1;
            else if(s[1]=='Q')  vis[3][12]=1;
            else if(s[1]=='K')  vis[3][13]=1;
            else if(s[1]=='A')  vis[3][1]=1;
            else    vis[3][s[1]-'0']=1;
        }else{
            if(s[1]=='T')   vis[4][10]=1;
            else if(s[1]=='J')  vis[4][11]=1;
            else if(s[1]=='Q')  vis[4][12]=1;
            else if(s[1]=='K')  vis[4][13]=1;
            else if(s[1]=='A')  vis[4][1]=1;
            else    vis[4][s[1]-'0']=1;
        }
    }
    int ans=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!vis[i][j])  ans++;
        }
    }
    cout<<ans;
    return 0;
}
