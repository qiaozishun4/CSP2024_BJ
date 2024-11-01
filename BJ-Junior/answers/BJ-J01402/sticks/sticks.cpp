#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
LL T;
LL h[8] = {0,0,1,7,4,2,6,8};
LL cal(LL n){
    if(n-2 <= 7)
        return 10 + h[n-2];
    else if(n-5 <= 7)
        return 20 + h[n-5];
    else if(n == 13)
        return 68;
    else
        return 88;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    for(LL i = 1; i <= T; i++){
        LL n;
        cin >> n;
        if(n == 1)
            cout << -1 << endl;
        else if(n < 8)
            cout << h[n] << endl;
        else if(n <= 14){
            cout << cal(n) << endl;
        }
        else if(n == 15)
            cout << 188 << endl;
        else if(n == 16)
            cout << 202 << endl;
        else if(n == 17)
            cout << 200 << endl;
        else if(n == 18)
            cout << 208 << endl;
        else if(n == 19)
            cout << 288 << endl;
        else if(n == 20)
            cout << 688 << endl;
        else
            for(int i = 1; i <= n/7; i++)
                cout << 8;
    }
    return 0;
}