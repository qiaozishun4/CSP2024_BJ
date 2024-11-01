#include<iostream>
using namespace std;
#define ll long long
ll n;
char op1,op2;
ll t[128][128];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    ll val,vbl;
    for (int i = 1;i <= n;i++){
        cin >>op1 >>op2;
        val = op1 - '0';
        vbl = op2 - '0';
        t[val][vbl]++;
    }
    ll ans = 0;
    for (int i = 1;i <= 128;i++){
        for (int j = 1;j <= 128;j++){
            if (t[i][j] != 0){
                ans++;
            }
        }
    }
    cout << 52-ans;
    return 0;
}
