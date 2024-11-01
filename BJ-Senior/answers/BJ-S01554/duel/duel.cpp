#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans;
bool flag[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int j=n-1;
    for(int i=n;i>1;i--){
        while(j>=1 and !flag[j] and flag[i]==0){
            if(a[i]>a[j]) {
                ans--;
                break;
                j--;
            }
            j--;
        }
    }
    cout<<ans;
    return 0;
}
