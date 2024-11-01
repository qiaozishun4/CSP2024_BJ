#include<bits/stdc++.h>
using namespace std;

int n;
int T;

int numss[7000];

int nums[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin >> T;
    for (int i = 100; i <= 999; i++) {
        int firstpos = (i % 100) % 10;
        int secondpos = ((i % 100) - firstpos) / 10;
        int thirdpos = (i - secondpos*10 - firstpos) / 100;
        numss[i] = nums[firstpos] + nums[secondpos] + nums[thirdpos];
    }
    for (int i = 10; i <= 99; i++) {
        int firstpos = i % 10;
        int secondpos = (i - firstpos) / 10;
        numss[i] = nums[firstpos] + nums[secondpos];
    }
    while (T--) {
        cin >> n;
        if (n > 7 && n <= 20) {
            bool flagg = false;
            for (int i = 10; i <= 999; i++) {
                if (numss[i] == n) {
                    cout << i << "\n";
                    flagg = true;
                    break;
                }
            }
            if (!flagg) cout << "-1" << "\n";
        }
        else if (n > 50) {
            int k = n / 7; //k the number of numpos
            for (int i = 1; i <= k; i++) {
                cout << 8;
            }
            cout << "\n";
        }
        else {
            bool flag = false;
            for (int i = 0; i <= 9; i++) {
                if (i == 0) continue;
                if (nums[i] == n) {
                    cout << i << "\n";
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "-1" << "\n";
            }
        }
    }
    return 0;
}
