#include<iostream>
using namespace std;
int n,ans;
bool p[53];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    while(n--) {
        string s;
        cin>>s;
        int t;
        if(s[0]=='C') t=0;
        if(s[0]=='S') t=13;
        if(s[0]=='H') t=26;
        if(s[0]=='D') t=39;
        if(s[1]>='2' && s[1]<='9') t+=(s[1]-'0');
        if(s[1]=='A') t++;
        if(s[1]=='T') t+=10;
        if(s[1]=='J') t+=11;
        if(s[1]=='Q') t+=12;
        if(s[1]=='K') t+=13;
        p[t]=true;
    }
    for(int i=1;i<=52;i++)
        if(!p[i])
            ans++;
    cout<<ans<<endl;
    return 0;
}