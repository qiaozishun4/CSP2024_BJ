#include<bits/stdc++.h>
using namespace std;
int n;
string dpv[100001];
int dp[100001];
int ans[22] = {0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88};
int num[7] = {888,108,188,200,208,288,688};

int main(){
    freopen("sticks2.in","r",stdin);
    freopen("sticks1.out","w",stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cin >> n;
        if(n <= 14){
            cout << ans[n] << '\n';
        }else{
            cout << num[n%7];
            for(int i = 1; i <= n/7-2-(n%7 == 0); i++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}
