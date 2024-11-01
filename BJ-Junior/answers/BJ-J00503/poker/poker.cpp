#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
int d[N], c[N], h[N], ss[N];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        string r;
        int x = 1;
        cin>>r;
        if(r[1] <= '9' && r[1] >= '2') x = r[1] - '0';
        else if(r[1] == 'A') x = 1;
        else if(r[1] == 'T') x = 10;
        else if(r[1] == 'J') x = 11;
        else if(r[1] == 'Q') x = 12;
        else if(r[1] == 'K') x = 13;
        if(r[0] == 'D') d[x] = 1;
        else if(r[0] == 'C') c[x] = 1;
        else if(r[0] == 'H') h[x] = 1;
        else if(r[0] == 'S') ss[x] = 1;
    }
    int ans = 0;
    for(int i = 1; i <= 13; i++){
        if(d[i] == 0) ans++;
        if(c[i] == 0) ans++;
        if(h[i] == 0) ans++;
        if(ss[i] == 0) ans++;
    }
    cout<<ans;
    return 0;
}
