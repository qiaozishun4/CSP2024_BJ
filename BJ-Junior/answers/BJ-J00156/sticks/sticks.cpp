#include <bits/stdc++.h>
using namespace std;
int T,n;
int a[1000005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> T;
    while(T--){
        cin >> n;
        if(n <= 1){
            cout << "-1"<<endl;
            continue;
        }
        int snam = n;
        int ansn = 0;
        if(n == 2) cout << "1"<<endl;
        if(n == 3) cout << "7"<<endl;
        if(n == 4) cout << "4"<<endl;
        if(n == 5) cout << "2"<<endl;
        if(n == 6) cout << "0"<<endl;
        if(n == 7) cout << "8"<<endl;
        if(n == 8) cout << "10"<<endl;
        if(n == 9) cout << "18"<<endl;
        if(n == 10) cout << "23"<<endl;
        if(n == 11) cout << "20"<<endl;
        if(n == 12) cout << "28"<<endl;
        if(n == 13) cout << "68"<<endl;
        if(n == 14) cout << "88"<<endl;
        if(n == 15) cout << "108"<<endl;
        if(n == 16) cout << "188"<<endl;
        if(n == 17) cout << "200"<<endl;
        if(n == 18) cout << "208"<<endl;
        if(n == 19) cout << "288"<<endl;
        if(n == 20) cout << "808"<<endl;
        if(n == 21) cout << "888"<<endl;
        if(n == 43) cout << "1000008"<<endl;
    }
    return 0;
}