#include<bits/stdc++.h>
using namespace std;
int n,a[60],ans;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--){
        cin>>s;
        int cnt=0;
        if(s[1]=='A') s[1]='1';
        if(s[0]=='C') cnt=13;
        else if(s[0]=='H') cnt=26;
        else if(s[0]=='S') cnt=39;

        if(s[1]=='T') a[cnt+10]=1;
        else if(s[1]=='J') a[cnt+11]=1;
        else if(s[1]=='Q') a[cnt+12]=1;
        else if(s[1]=='K') a[cnt+13]=1;
        else a[cnt+(s[1]-'0')]=1;
    }
    for(int i=1;i<=52;i++){
        if(a[i]==0) ans++;
    }
    cout<<ans;
    return 0;
}
