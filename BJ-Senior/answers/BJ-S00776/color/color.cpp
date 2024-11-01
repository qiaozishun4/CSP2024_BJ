#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[200050],hu;
long long ans;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof a);
        cin>>n;
        hu = 1;
        for(int i = 1;i <= n;i++){
            cin>>a[i];
            if(a[i] != a[i-1] && i != 1){
                hu = 0;
            }
        }
        if(hu){
            ans = (n-1)*a[1];
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}