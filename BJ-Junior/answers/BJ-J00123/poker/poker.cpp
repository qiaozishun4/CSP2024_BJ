#include<bits/stdc++.h>
using namespace std;
#define int long long
struct A{
    char a,b;
}a[105];
int n,p[53],ans;
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x,y;
        cin >> a[i].a >> a[i].b;
        if(a[i].a == 'D') x = 1;
        else if(a[i].a == 'C') x = 2;
        else if(a[i].a == 'H') x = 3;
        else if(a[i].a == 'S') x = 4;

        if(a[i].b == 'A') y = 1;
        else if(a[i].b == '2') y = 2;
        else if(a[i].b == '3') y = 3;
        else if(a[i].b == '4') y = 4;
        else if(a[i].b == '5') y = 5;
        else if(a[i].b == '6') y = 6;
        else if(a[i].b == '7') y = 7;
        else if(a[i].b == '8') y = 8;
        else if(a[i].b == '9') y = 9;
        else if(a[i].b == 'T') y = 10;
        else if(a[i].b == 'J') y = 11;
        else if(a[i].b == 'Q') y = 12;
        else if(a[i].b == 'K') y = 13;

        p[(x-1) * 13 + y] = 1;
    }
    for(int i = 1; i <= 52; i++){
        if(p[i] == 0) ans++;
    }
    cout << ans;
    return 0;
}
