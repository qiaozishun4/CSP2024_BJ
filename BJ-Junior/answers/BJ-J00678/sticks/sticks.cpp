#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int d[10] = {6,2,5,4,6,3,7};//6,2,5,4,6,3,7
int m[10] = {0,1,2,4,6,7,8};
long long a[100005];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    for (int i = 1;i<=1e5+2;i++){
        a[i] = -1;
    }
    a[2] = 1;a[3] = 7;a[4] = 4;a[5] = 2;a[6] = 6;a[7] = 8;a[18] = 208;a[8] = 16;
    for (int i = 82;i<=100000;i++){
            for (int j = 0;j<7;j++){
                if ((a[i]<(a[i-d[j]]*10+m[j]))&&a[i]!=-1)
                a[i] = min(a[i],a[i-d[j]]*10+m[j]);
                else a[i] = a[i-d[j]]*10+m[j];
            }
        }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout <<a[n] <<endl;
    }
    return 0;
}
