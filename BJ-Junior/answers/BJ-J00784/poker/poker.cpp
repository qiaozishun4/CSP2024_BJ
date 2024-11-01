#include<bits/stdc++.h>
using namespace std;
int a[2000],cnt,n,t;
char s[2];
int main() {
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        t=0;
        if(s[0]=='D') t=0;
        else if(s[0]=='C') t=13;
        else if(s[0]=='H') t=26;
        else if(s[0]=='S') t=39;
        //cout<<t<<"a\n";
        if(s[1]>='A'&&s[1]>='Z') {
            if(s[1]=='A') t++;
            else if(s[1]=='T') t+=10;
            else if(s[1]=='J') t+=11;
            else if(s[1]=='Q') t+=12;
            else if(s[1]=='K') t+=13;
            //cout<<t<<"b\n";
        }else {
            t+=s[1]-'0';
        }
        a[t]++;
        //cout <<t<<';';
    }
    for(int i=125;i>=1;i--) {
        if(a[i]>=4) cnt+=4;
        else cnt+=a[i];
    }
    cout <<52-cnt;
    return 0;
}
