#include <iostream>
#include <cmath>
using namespace std;

// m[i] means the cost of using number i
//    i =  0 1 2 3 4 5 6 7 8 9
long long m[] = {6,2,5,5,4,5,6,3,7,6};
// only 2~7

long long cost(long long x){
    long long ans = 0;
    while (x){
        ans += m[x % 10];
        // cout << "x%10=" << x%10 << "     ";
        x /= 10;
        // cout << "x=" << x << endl;
    }
    return ans;
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    long long T;
    long long n;
    long long base;
    long long ans;
    cin >> T;
    while (T--){
        cin >> n;
        base = ans = 0;
        long long i = 1;
        if (n < 2){
            cout << -1 << endl;
            continue;
        }
        while (i < 21474836){
            if (cost(i) == n){
                break;
            }
            i++;
        }
        if (i == 21474836){
            cout << -1 << endl;
        }
        else cout << i << endl;
    }
    return 0;
}