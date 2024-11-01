#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
const int N = 5e4 + 5;
int n;
int num[] = {6, 2, 5, 5, 4, 2, 6, 3, 7, 6};
bool flag;
void soloved() {
    cin >> n;
    for(int i = 0; i <= n * n; i ++) {
        int sum = 0;
        int ii = i;
        while(ii) {
            sum += num[ii % 10];
            ii /= 10;
        }
        if(sum == n && sum != 0) {
            flag = true;
            cout << i <<endl;
            return ;
        }
    }
    cout << -1 <<endl;
    return ;

}
int main() {
      freopen("sticks.in", "r", stdin);
      freopen("sticks.out", "w", stdout);
//    ios_sync_with_stdio(false);
//    cin.tie;
//    cout.tie;
    int t = 1;
    cin >> t;
    while(t--) {
        soloved();
    }

}

