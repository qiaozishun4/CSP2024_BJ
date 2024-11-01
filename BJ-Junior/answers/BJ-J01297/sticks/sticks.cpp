#include <bits/stdc++.h>
using namespace std;
int t,n;
int use[21] = {0,-1,1,7,4,2,6,8,10,18,22,20,60,68,88,108,188,200,208,288,688};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n <= 20) cout << use[n];
        else{
            if(n%7 == 0) for(int i = 1;i <= n/7;i ++) cout << "8";
            else if(n%7 == 1){
                cout << "10";
                for(int i = 1;i <= (n-8)/7;i ++) cout << "8";
            }else cout << "-1";
        }
        cout << "\n";
    }
    fclose(stdin);
    fclose(stdout);
}
