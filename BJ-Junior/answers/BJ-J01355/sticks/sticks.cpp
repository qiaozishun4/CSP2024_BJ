#include<iostream>
using namespace std;

int a[7] = {-1,-1,1,7,4,2,6},b[7] = {8,16,18,22,20,28,68};

int main(){
    ios::sync_with_stdio(false);
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n < 7){
            cout << a[n] << endl;
        }
        else{
            int q = n/7,r = n%7;
            cout << b[r];
            for(int i = 1; i < q; i++){
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
