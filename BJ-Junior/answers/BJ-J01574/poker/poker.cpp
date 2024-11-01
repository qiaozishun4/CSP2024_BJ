#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll f[5][14];
string s;
ll check(char t){
    if(t>='0'&&t<='9'){
        return t-'0';
    }else{
        if(t=='T'){
            return 10;
        }
        if(t=='J'){
            return 11;
        }
        if(t=='Q'){
            return 12;
        }
        if(t=='K'){
            return 13;
        }
        if(t=='A'){
            return 1;
        }
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='S'){
            f[1][check(s[1])]=1;
        }else if(s[0]=='H'){
            f[2][check(s[1])]=1;
        }else if(s[0]=='C'){
            f[3][check(s[1])]=1;
        }else{
            f[4][check(s[1])]=1;
        }
    }
    ll cnt=0;
    for(ll i=1;i<=4;i++){
        for(ll j=1;j<=13;j++){
            if(f[i][j]==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
