#include<bits/stdc++.h>
#define int long long
using namespace std;
bool d[1000];
bool c[1000];
bool h[1000];
bool s[1000];
char id[13]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D'){
            d[b]=1;
        }if(a=='C'){
            c[b]=1;
        }if(a=='S'){
            h[b]=1;
        }if(a=='H'){
            s[b]=1;
        }
    }
    int num=0;
    for(int i=0;i<=12;i++){
        if(d[id[i]]==0){
            num++;
        }
        if(c[id[i]]==0){
            num++;
        }
        if(h[id[i]]==0){
            num++;
        }
        if(s[id[i]]==0){
            num++;
        }
    }
    cout<<num;
    return 0;
}
