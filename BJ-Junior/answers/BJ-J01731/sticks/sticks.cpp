#include<bits/stdc++.h>
using namespace std;

int biao[55]={-1,-1,1,7,4,2,6,8,10,70,22,50,60,80,88,108,188,200,208,288,688};
int t,n;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        if (n % 7 == 0){
            for (int i = 1;i <= n/7;i++) cout << 8;
            cout << endl;
            continue;
        }
        if (n % 7 == 1){
            cout << 10;
            for (int i = 1;i <= (n-1)/7-1;i++) cout << 8;
            cout << endl;
            continue;
        }
        cout << biao[n] << endl;
    }
}