#include<bits/stdc++.h>
using namespace std;
int n,ans=52;
string s;
bool vis[60]={false};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<51;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>s;
        if(s[0]=='D'){
            if(s[1]=='T') vis[10]=true;
            if(s[1]=='J') vis[11]=true;
            if(s[1]=='Q') vis[12]=true;
            if(s[1]=='K') vis[13]=true;
            if(s[1]>='0'&&s[1]<='9') vis[s[1]-'0']=true;
        }
        if(s[0]=='C'){
            if(s[1]=='T') vis[23]=true;
            if(s[1]=='J') vis[24]=true;
            if(s[1]=='Q') vis[25]=true;
            if(s[1]=='K') vis[26]=true;
            if(s[1]>='0'&&s[1]<='9') vis[s[1]-'0'+13]=true;
        }
        if(s[0]=='H'){
            if(s[1]=='T') vis[36]=true;
            if(s[1]=='J') vis[37]=true;
            if(s[1]=='Q') vis[38]=true;
            if(s[1]=='K') vis[39]=true;
            if(s[1]>='0'&&s[1]<='9') vis[s[1]-'0'+26]=true;
        }
        if(s[0]=='S'){
            if(s[1]=='T') vis[49]=true;
            if(s[1]=='J') vis[50]=true;
            if(s[1]=='Q') vis[51]=true;
            if(s[1]=='K') vis[52]=true;
            if(s[1]>='0'&&s[1]<='9') vis[s[1]-'0'+39]=true;
        }
    }
    for(int i=1;i<=52;i++)
        if(vis[i]) ans--;
    cout<<ans<<endl;
    return 0;
}
