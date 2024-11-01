#include<bits/stdc++.h>
using namespace std;
map<string,bool>vis;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.ans","w",stdout);
    int n,ans=0;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(!vis[s]){
            ans++;
            vis[s]=1;
        }
    }
    cout<<52-ans<<endl;
    return 0;
}
