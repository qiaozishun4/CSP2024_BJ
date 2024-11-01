#include <bits/stdc++.h>
using namespace std;
int a[10]={6,2,5,4,5,6,3,7,6};
int ans=10000000;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                if(a[i]+a[j]==n){
                    ans=min(ans,i*10+j);
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
