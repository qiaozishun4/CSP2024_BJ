#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int cnt=0;
        int n,k=0;
        cin>>n;
        while(n--){
            int x;
            cin>>x;
            if(k>=x)    cnt+=x;
            k=x;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
