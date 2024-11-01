#include <bits/stdc++.h>
using namespace std;
int a[15]={6,2,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int m;
        cin>>m;
        for(int i=1;i*7<=m;i++){
            cout<<"8";
        }
    }
    return 0;
}
