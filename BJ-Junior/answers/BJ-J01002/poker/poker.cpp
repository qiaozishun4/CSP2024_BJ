#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string t[102],s;
inline void find(string x){
    for(int i=1;i<=cnt;i++){
        if(t[i]==x)return;
    }
    t[++cnt]=x;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(register int i=1;i<=n;i++){
        cin>>s;
        find(s);
    }
    cout<<(52-cnt);
    return 0;
}
