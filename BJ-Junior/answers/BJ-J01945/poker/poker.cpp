#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
string s;
long long d[maxn],c[maxn],h[maxn],e[maxn],n,ans;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>s;
        if(s[0]=='D'){
            d[int(s[1])]++;
            //cout<<'D'<<endl;
        }
        else if(s[0]=='C'){
            c[int(s[1])]++;
            //cout<<'C'<<endl;
        }else if(s[0]=='H'){
            h[int(s[1])]++;
            //cout<<'H'<<endl;
        }else if(s[0]=='S'){
            e[int(s[1])]++;
            //cout<<e[int(s[1])]<<endl;
            //cout<<int(s[1])<<endl;
        }
    }
    for(int i = 1;i<=84;i++){
        if(d[i]!=0)ans++;
        if(c[i]!=0)ans++;
        if(h[i]!=0)ans++;
        if(e[i]!=0)ans++;
        //cout<<d[i]<<" "<<c[i]<<" "<<h[i]<<" "<<e[i]<<endl;
    }
    cout<<52-ans;
    return 0;
}
