#include<iostream>
#include<cstring>
using namespace std;

int a[60];

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        int t=0;
        cin>>s;
        if(s[0]=='S') t+=0;
        else if(s[0]=='C') t+=13;
        else if(s[0]=='H') t+=26;
        else if(s[0]=='D') t+=39;
        if(s[1]=='A') t+=1;
        else if(s[1]=='T') t+=10;
        else if(s[1]=='J') t+=11;
        else if(s[1]=='Q') t+=12;
        else if(s[1]=='K') t+=13;
        else t+=int(s[1]-'0');
        a[t]++;
    }
    for(int i=1;i<=52;i++){
        if(a[i]==0) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
