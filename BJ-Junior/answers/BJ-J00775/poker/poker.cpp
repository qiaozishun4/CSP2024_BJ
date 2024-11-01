#include <bits/stdc++.h>
using namespace std;
int n,t[100][200];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        string a;
        cin >> a;
        if(a[1] == 'A') a[1] = 'a';
        if(a[1] == 'T') a[1] = 'b';
        if(a[1] == 'J') a[1] = 'c';
        if(a[1] == 'Q') a[1] = 'd';
        if(a[1] == 'K') a[1] = 'e';
        t[a[0] - 'A'][a[1]] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= 100;i++){
        for(int j = 1;j <= 200;j++){
            if(t[i][j] == 1) ans++;
        }
    }
    cout << 52 - ans;
    return 0;
}
