#include <bits/stdc++.h>
using namespace std;
int sz[52] = {-1,-1 ,1, 7, 4, 2, 6, 8, 10, 18, 22,20, 28, 68, 88, 108, 188, 228 ,208, 288, 688 , 888 , 1288,1088,1888,2488,2088,2888,6888,8888,12888,10888,18888,24888,20888,68888,88888,128888,108888,188888,248888,108888,688888,888888,1288888,1088888,688888,8888888,12888888,10888888,6888888,88888888};
int out[30] = {0};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int t;
    cin >> t;
    for(int i = 0;i < t;i++){
int a;
cin >> a;
out[i]=sz[a];
    }
    for(int i = 0;i < t;i++){
        cout << out[i] << endl;
    }
return 0;
}
