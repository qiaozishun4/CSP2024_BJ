#include<bits/stdc++.h>
using namespace std;
//poker
int n, ans;
char a, b;
bool visd[13], visc[13], vish[13], viss[13];
int main(){
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a >> b;
        if(a == 'D') if('2' <= b && b <= '9') visd[b-'0'-1] = true;
            else if(b == 'A') visd[0] = true; else if(b == 'T') visd[9] = true;
            else if(b == 'J') visd[10] = true; else if(b == 'Q') visd[11] = true; else visd[12] = true;
        else if(a == 'C') if('2' <= b &&  b<= '9') visc[b-'0'-1] = true;
            else if(b == 'A') visc[0] = true; else if(b == 'T') visc[9] = true;
            else if(b == 'J') visc[10] = true; else if(b == 'Q') visc[11] = true; else visc[12] = true;
        else if(a == 'H') if('2' <= b && b <= '9') vish[b-'0'-1] = true;
            else if(b == 'A') vish[0] = true; else if(b == 'T') vish[9] = true;
            else if(b == 'J') vish[10] = true; else if(b == 'Q') vish[11] = true; else vish[12] = true;
        else if('2' <= b && b <= '9') viss[b-'0'-1] = true;
            else if(b == 'A') viss[0] = true; else if(b == 'T') viss[9] = true;
            else if(b == 'J') viss[10] = true; else if(b == 'Q') viss[11] = true; else viss[12] = true;
    }
    for(int i = 0;i < 13;i++) if(visd[i] == 0) ans++;
    for(int i = 0;i < 13;i++) if(visc[i] == 0) ans++;
    for(int i = 0;i < 13;i++) if(vish[i] == 0) ans++;
    for(int i = 0;i < 13;i++) if(viss[i] == 0) ans++;
    cout << ans << endl;
    return 0;
}
