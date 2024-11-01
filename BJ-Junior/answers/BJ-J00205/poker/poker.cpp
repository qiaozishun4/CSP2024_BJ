#include<bits/stdc++.h>
using namespace std;
char hs[10]="SHDC";
char p[20]="A23456789TJQK";
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<string,bool>mp;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        mp[s]=1;
    }
    int ans=0;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            string s="";
            s+=hs[j];
            s+=p[i];
            if(!mp[s])ans++;
        }
    }
    cout<<ans;
    return 0;
}
