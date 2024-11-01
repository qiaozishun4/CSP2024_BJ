#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[14] = {-1, -1, 1, 7, 4, 2, 6, 12, 10, 18, 22, 20};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t-- && t >= 0){
        int n;
        cin >> n;
        if(n == 1 || n == 0){
            cout << -1 << endl;
            continue;
        }
        if(n%7 == 0){
            for(int i = 1; i <= n/7; i++)
                cout << 8;
            cout << endl;
        }else if(n%7 == 1){
            cout << 16;
            for(int i = 1; i < n/7; i++)
                cout << 8;
            cout << endl;
        }else{
            cout << a[n%7+7];
            for(int i = 1; i < n/7; i++)
                cout << 8;
            cout << endl;
        }
    }
    return 0;
}