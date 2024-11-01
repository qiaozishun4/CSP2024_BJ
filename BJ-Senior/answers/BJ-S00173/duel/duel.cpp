#include<bits/stdc++.h>
using namespace std;

int l[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,ans;
    cin>>n;
    ans=n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    sort(l,l+n);
    for(int i=1,j=0;i<n;i++){
        if(l[i]>l[j]){
            j++,ans--;
        }
    }
    cout<<ans;
    return 0;
}
