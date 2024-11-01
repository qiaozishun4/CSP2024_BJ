#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int a[7]={-1,-1,1,7,4,2,6};
int b[7]={8,10,18,22,20,28,68};
int t;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >> t;
    for(int i=1;i<=t;i++){
        int n;
        cin >> n;
        if(n<7) cout << a[n] << endl;
        else{
            cout << b[n%7];
            int n1=n/7-1;
            for(int i=1;i<=n1;i++){
                cout << 8;
            }
            cout << endl;
        }
    }
    return 0;
}
