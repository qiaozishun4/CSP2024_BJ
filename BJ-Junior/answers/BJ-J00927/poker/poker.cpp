#include<bits/stdc++.h>
using namespace std;
int fangpian[100],caohua[100],hongtao[100],heitao[100];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n=0,m=0;cin>>n;
    if(n==1){
        cout<<51;return 0;
    }
    char s[5];
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[1]=='A')m=1;
        else if(s[1]=='2')m=2;
        else if(s[1]=='3')m=3;
        else if(s[1]=='4')m=4;
        else if(s[1]=='5')m=5;
        else if(s[1]=='6')m=6;
        else if(s[1]=='7')m=7;
        else if(s[1]=='8')m=8;
        else if(s[1]=='9')m=9;
        else if(s[1]=='T')m=10;
        else if(s[1]=='J')m=11;
        else if(s[1]=='Q')m=12;
        else if(s[1]=='K')m=13;
        if(s[0]=='D')fangpian[m]++;
        if(s[0]=='C')caohua[m]++;
        if(s[0]=='H')hongtao[m]++;
        if(s[0]=='S')heitao[m]++;
    }
    int ans=0;
    for(int i=1;i<=13;i++){
        if(fangpian[i]==0)ans++;
        if(caohua[i]==0)ans++;
        if(hongtao[i]==0)ans++;
        if(heitao[i]==0)ans++;
    }
    cout<<ans;
    return 0;
}
