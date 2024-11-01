#include <iostream>
using namespace std;

int a[800010] = {-1,-1,1,7,4,2,6,8};
int v[100010] = {6,2,5,5,4,5,6,3,7,6};
int t;
int n;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for(int i = 10;i <= 10001;i++){
        v[i] = v[i / 10] + v[i % 10];
        if(a[v[i]] == 0)a[v[i]] = i;
    }
    cin >> t;
    for(int i = 1;i <= t;i++){
        cin >> n;
        if(a[n] == 0)cout << "-1" << endl;
        else cout << a[n] << endl;
    }
    return 0;
}
