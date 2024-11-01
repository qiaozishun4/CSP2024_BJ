#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >>T;
    for(int I=1;I<=T;I++){
        int a;
        cin >> a;
        if(a%7==0){
            a/=7;
            for(int i=1;i<=a;i++){
                cout << 8;
            }
            cout << "\n";
        }
        else if(a%7==1){
            a/=7;
            cout << 10;
            a--;
            for(int i=1;i<=a;i++){
                cout << 8;
            }
            cout << "\n";
        }
        else {
            cout << -1 << "\n";
        }
    }
    return 0;
}
