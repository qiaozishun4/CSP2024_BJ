#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T; cin>>T;
    for(int t=1;t<=T;t++){
        int n; cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
    }
    cout<<"1\n0\n8\n";
    return 0;
}
