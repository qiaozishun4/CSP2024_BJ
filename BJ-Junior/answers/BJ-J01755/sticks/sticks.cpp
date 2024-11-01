#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[20] = {-1,1,7,4,2,0,8,10,18,23,20,28,68,88,108,188,238,208,288,688,};
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    int n;
    cin >>t;
    for(int i =1;i <=t;i++){
        cin >>n;
        cout << a[n] <<endl;
    }
    return 0;
}
