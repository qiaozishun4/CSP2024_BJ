#include<bits/stdc++.h>
using namespace std;
long long t, n, ans = 541881145141919810;
long long num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
//                   0  1  2  3  4  5  6  7  8  9
long long st[21] = {-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,188,688};
int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n <= 20){
            cout<<st[n]<<endl;
            continue;
        }
        int num8 = n / 7 - 2;
        int r = n % 7 + 14;
        if(num8 >= 0){
            cout<<st[r];
            for(int i = 1; i <= num8; i++) cout<<8;
            cout<<endl;
        }
        else{
            if(num8 > 0){
                num8 += 1;
                r -= 7;
                cout<<st[r];
                for(int i = 1; i <= num8; i++) cout<<8;
                cout<<endl;
            }
            else{
                num8 += 1;
                r -= 7;
                cout<<st[r];
                for(int i = 1; i <= num8; i++) cout<<8;
                cout<<endl;
            }
        }

    }
    return 0;
}

