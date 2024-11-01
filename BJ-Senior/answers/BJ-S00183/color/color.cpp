#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int a[10000001];
    int t,k,ans;
    cin>>t;
    for(int i=0;i<t;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>k;
            a[k]++;
        }
        for(int j=1;j<10000000;j++){
            if(a[j]>=2){
                ans+=(a[j]-1)*j;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
