#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+7;
int a[N];
bool v[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1,r=2;
    //136 136 136 136 136 136 136 136 2417 2417
    //1 1 1
    while(r<=n){
        if(a[r]>a[l]){
            v[l]=1;
            l++;
            r++;
        }else{
            r++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
