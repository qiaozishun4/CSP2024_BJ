#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[10] = {6,2,5,5,4,5,6,3,7,6};
int sum(int n){
    int t = n;
    int ans = 0;
    while(t>0){
        ans += a[t%10];
        t /= 10;
    }
    return ans;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        if(n==1){
            cout << -1 << endl;
            continue;
        }
        if(n<= 50){
            for(int i = 1; true; i++){
                int ans = sum(i);
                if(ans==n){
                    cout << i <<endl;
                    break;
                }
            }
        }else{
            if(n % 7 == 0){
                int f = n/7;
                for(int i = 1; i<= f; i++){
                    cout << 8;
                }
                cout << endl;
            }
            if(n % 7 == 1){
                cout << 10;
                n -= 8;
                int f = n/7;
                for(int i = 1; i<= f; i++){
                    cout << 8;
                }
                cout << endl;
            }
            if(n % 7 == 2){
                cout << 1;
                n-=2;
                int f = n/7;
                for(int i = 1; i<= f; i++){
                    cout << 8;
                }
                cout << endl;
            }
            if(n % 7 == 3){
                cout << 23;
                n-=10;
                int f = n/7;
                for(int i = 1; i<= f; i++){
                    cout << 8;
                }
                cout << endl;
            }
            if(n % 7 == 4){
                cout << 20;
                n -= 11;
                int f = n/7;
                for(int i = 1; i<= f; i++){
                    cout << 8;
                }
                cout << endl;
            }
            if(n % 7 == 5){
                cout << 2;
                n -= 5;
                int f = n/7;
                for(int i = 1; i<= f; i++){
                    cout << 8;
                }
                cout << endl;
            }
            if(n % 7 == 6){
                cout << 6;
                n -= 6;
                int f = n/7;
                for(int i = 1; i<= f; i++){
                    cout << 8;
                }
                cout << endl;
            }
        }
    }
    return 0;
}
