#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin >>T;
    while(T--){
        int n;
        cin >>n;
        if(n == 1) cout <<-1<<endl;
        else if(n == 2) cout <<1<<endl;
        else if(n%7 == 0){
            for(int i=1;i<=n/7;i++){
                cout <<8;
            }
            cout <<endl;
        }
        else if((n-1)%7 == 0){
            n -= 8;
            cout << 10;
            for(int i=1;i<=n/7;i++){
                cout <<8;
            }
            cout <<endl;
        }
    }
    return 0;
}