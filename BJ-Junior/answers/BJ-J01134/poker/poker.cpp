#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
static const int N=1e4+5;
int b[N];
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,cnt=52;
    string s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        b[(int)s[1]+s[0]]++;
    }
    for(int i=1;i<=300;i++){
        if(b[i]==1){
            cnt-=1;
        }else if(b[i]>1){
            cnt-=1;
        }else continue;
    }
    cout<<cnt;
    return 0;
}
