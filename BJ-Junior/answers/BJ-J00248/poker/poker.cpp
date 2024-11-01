#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n;
string c[4]={"S","H","C","D"};
char h[5]={'A','T','J','Q','K'};
string s;
unordered_map<string,bool>mp;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        mp[s]=1;
    }
    int ans=0;
    for(int d=0;d<4;d++){
        string x=c[d];
        for(int i=2;i<10;i++){
            if(mp[x+to_string(i)]==0)ans++;
        }
        for(int l=0;l<5;l++){
            if(mp[x+h[l]]==0)ans++;
        }
    }
    cout<<ans<<'\n';
}