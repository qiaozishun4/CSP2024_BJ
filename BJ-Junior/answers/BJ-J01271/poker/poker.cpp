#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
string s[90];
const string c="DCHS";
const string p="A23456789TJQK";
int ans=52;
map<string,int> m;
void slv(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i],m[s[i]]++;
    for(int i=0;i<4;i++){
        for(int j=0;j<p.length();j++){
           string tmp="";
           tmp+=c[i];
           tmp+=p[j];
            if(m[tmp])ans--;
        }
    }
    cout<<ans<<endl;
    return;
}
signed main(){
 freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
slv();
return 0;
}
