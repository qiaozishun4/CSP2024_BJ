#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
string s_;
int n,a[5][N],ans=52;
int fir(char x){
    if(x=='D')return 1;
    if(x=='C')return 2;
    if(x=='H')return 3;
    if(x=='S')return 4;
}
int sec(char x){
    if(x>='2'&&x<='9')return x-'0';
    if(x=='T')return 10;
    if(x=='J')return 11;
    if(x=='Q')return 12;
    if(x=='K')return 13;
    if(x=='A')return 1;
}
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s_;
        if(a[fir(s_[0])][sec(s_[1])]==0){
            ans--;
            a[fir(s_[0])][sec(s_[1])]=1;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
