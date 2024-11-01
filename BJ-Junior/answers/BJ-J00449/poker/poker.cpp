#include<bits/stdc++.h>
using namespace std;
int hs1[105];
int hs2[105];
int hs3[105];
int hs4[105];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int j=0;
        if(s[1]-'0'>=2&&s[1]-'0'<=9)j=s[1]-'0';
        else if(s[1]=='A')j=1;
        else if(s[1]=='T')j=10;
        else if(s[1]=='J')j=11;
        else if(s[1]=='Q')j=12;
        else j=13;
        if(s[0]=='D')hs1[j]=1;
        else if(s[0]=='C')hs2[j]=1;
        else if(s[0]=='H')hs3[j]=1;
        else hs4[j]=1;
    }
    int ans=52;
    for(int i=1;i<=13;i++){
        if(hs1[i]==1)ans--;
        if(hs2[i]==1)ans--;
        if(hs3[i]==1)ans--;
        if(hs4[i]==1)ans--;
    }
    cout<<ans;
    return 0;
}
