#include <bits/stdc++.h>
using namespace std;
int n,cnt;
bool bkt[100];
int to(string s){
    int res=0;
    if(s[0]=='D') res=0;
    else if(s[0]=='C') res=1;
    else if(s[0]=='H') res=2;
    else if(s[0]=='S') res=3;
    res*=13;
    if('2'<=s[1]&&s[1]<='9') res+=s[1]-'0';
    else if(s[1]=='A') res+=1;
    else if(s[1]=='T') res+=10;
    else if(s[1]=='J') res+=11;
    else if(s[1]=='Q') res+=12;
    else if(s[1]=='K') res+=13;
    return res;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        bkt[to(s)]=1;
        //cout<<to(s)<<endl;
    }
    for(int i=1;i<=52;i++){
        if(bkt[i]==0){
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}