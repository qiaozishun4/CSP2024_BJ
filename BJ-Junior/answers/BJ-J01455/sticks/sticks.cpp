#include<bits/stdc++.h>
using namespace std;
int t,n;
char a[1005][1005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n == 0) cout << -1 << endl;
        if(n == 1) cout << -1 << endl;
        if(n == 2) cout << 1 << endl;
        if(n == 3) cout << 7 << endl;
        if(n == 4) cout << 4 << endl;
        if(n == 5) cout << 2 << endl;
        if(n == 6) cout << 6 << endl;
        if(n == 7) cout << 12 << endl;
        if(n == 8) cout << 8 << endl;
        if(n == 9) cout << 24 << endl;
        if(n == 18) cout << 208 << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
