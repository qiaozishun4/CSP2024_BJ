#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n = 52,ans = 52,j = 0,k;
    bool vis[4][13] = {};
    char a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        j = 0;
        k = 0;
        if(a == 'C')j = 1;
        else if(a == 'H')j = 2;
        else if(a == 'S')j = 3;
        if(b >= '2' && b <= '9')k = b - '1';
        else if(b == 'T')k = 9;
        else if(b == 'K')k = 12;
        else if(b == 'Q')k = 11;
        else if(b == 'J')k = 10;
        if(!vis[j][k]){
            ans--;
            vis[j][k] = 1;
        }
    }
    cout << ans;
    return 0;
}
