#include<bits/stdc++.h>
using namespace std;
long long n,t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    string s[7] = {"0","10","18","22","20","28","68"};
    cin >> t;
    while(t--){
        cin >> n;
        if(n < 2){
            cout << -1;
            cout << "\n";
        }
        if(n % 7 == 0){
            for(int i = 0; i < n / 7; i++)cout << '8';
            cout << "\n";
        }else{
            cout << s[n % 7];
            for(int i = 1; i < n / 7; i++)cout << '8';
            cout << "\n";
        }
    }
    return 0;
}