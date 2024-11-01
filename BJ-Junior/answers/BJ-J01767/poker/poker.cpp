#include <bits/stdc++.h>
using namespace std;
int a[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    if(n==52){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int m;
        if(s[1]>='2'&&s[1]<='9') m=s[1]-'0';
        else if(s[1]=='A') m=1;
        else if(s[1]=='T') m=10;
        else if(s[1]=='J') m=11;
        else if(s[1]=='Q') m=12;
        else if(s[1]=='K') m=13;
        if(s[0]=='D') a[1][m]=1;
        else if(s[0]=='C') a[2][m]=1;
        else if(s[0]=='H') a[3][m]=1;
        else if(s[0]=='S') a[4][m]=1;
    }
    int ans=0;
    for(int i=1;i<=4;i++) for(int j=1;j<=13;j++) if(!a[i][j]) ans++;
    cout<<ans;
    return 0;
}
