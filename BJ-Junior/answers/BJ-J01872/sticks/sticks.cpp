#include<bits/stdc++.h>
using namespace std;
int n, ans[10] = {0, -1, 1, 7, 4, 2, 6, 8};
void p(int x){
    for(int i=1; i<=n/7-x; i++)
        cout << '8';
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t; cin >> t;
    while(t--){
        cin >> n;
        if(1 <= n && n <= 7){
            cout << ans[n];
        }
        else if(n % 7 == 0){
            p(0);
        }
        else if(n % 7 == 1){
            cout << "10";
            p(1);
        }
        else{
            if(n % 7 == 2){
                cout << '1';
                p(0);
            }
            else if(n % 7 == 3){
                cout << "23";
                p(1);
            }
            else if(n % 7 == 4){
                cout << "20";
                p(1);
            }
            else if(n % 7 == 5){
                cout << '2';
                p(0);
            }
            else if(n % 7 == 6){
                cout << '6';
                p(0);
            }
        }
        cout << '\n';
    }
    return 0;
}