#include <iostream>
#include <cstdio>
using namespace std;
int matches[8] = {-1,-1,1,7,4,2,6,8};
int matches2[8] = {-1,-1,1,7,4,2,0,8};
int minn[8];
int minn2[8];
int original[10] = {6,2,5,5,4,5,6,3,7,6};

int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    minn[7] = matches[7];
    minn2[7] = matches2[7];
    for(int i = 6;i>=0;i --) {
        minn[i] = min(minn[i + 1],matches[i]);
        minn2[i] = min(minn2[i + 1],matches2[i]);
    }
    int t;
    cin>>t;
    while(t --) {
        int n;
        cin>>n;
        int left = n % 7;
        if(n < 2) {cout << -1 << endl; continue;}
        if(n <= 7) {
            cout << matches[n] << endl;
            continue;
        }
        if(n % 7 == 0) {
            for(int i = 1;i<=n / 7;i++) {
                cout << 8;
            }
            cout << endl;
        }
        else {
            if(matches[n % 7] == -1) {
                cout << 1 << 6;
                for(int i = 1;i<=n / 7 - 1;i++) {
                    cout << 8;
                }
                cout << endl;
            }
            else {
                cout << minn[n % 7]<<matches2[7 - original[minn[n%7]] + n % 7];
                for(int i = 1;i<=n / 7 - 1;i++) {
                    cout << 8;
                }
                cout << endl;
            }
        }
    }
    return 0;
}
