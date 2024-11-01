#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t,n;
    cin>> t;
    for (int i=1;i<=t; i++){
        cin >> n;
        if (n<=1) cout << -1 << endl;
        if (n!=0&&n%7==0){
            for (int j=1;j<=n/7;j++)
                cout << 8;
            cout << endl;
        }
        if (n!=1&&n%7==1){
            cout << 10;
            for (int j=1;j<=n/7-1;j++)
                cout << 8;
            cout << endl;
        }
    }

    return 0;
}
