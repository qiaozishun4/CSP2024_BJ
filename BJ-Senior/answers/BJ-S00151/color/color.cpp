#include<bits/stdc++.h>
using namespace std;
int n;
int a[200020];
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int rans=-1;
        for(int i=0;i<(1<<n);i++){
            int ans=0;
            for(int j=1;j<n;j++){
                int xx=j-1;
                while(xx>=0&&(((i>>j)&1)!=((i>>xx)&1))){
                    xx--;
                }
                if((((i>>j)&1)==((i>>xx)&1))&&a[j]==a[xx]){
                    ans+=a[xx];
                }
            }
            rans=max(ans, rans);
        }
        cout<<rans<<endl;
    }
    return 0;
}