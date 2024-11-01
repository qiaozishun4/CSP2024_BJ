#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[60],ans;
char s[5];
int shu(char c){
    if(c=='A')return 1;
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
    return c-48;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[0]>>s[1];
        if(s[0]=='D')a[shu(s[1])]++;
        if(s[0]=='C')a[shu(s[1])+13]++;
        if(s[0]=='H')a[shu(s[1])+26]++;
        if(s[0]=='S')a[shu(s[1])+39]++;
    }
    for(int i=1;i<=52;i++){
        if(a[i]==0){ans++;}
    }
    cout<<ans<<endl;
    return 0;
}

