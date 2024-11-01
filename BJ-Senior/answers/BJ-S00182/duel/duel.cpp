#include<bits/stdc++.h>
using namespace std;
int a[100010];
int n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=n;
    int s=0;
    for(int i=1;i<n;i++){
        while(a[s]<=0){
            s++;
            ans--;
        }
        if(a[i]>a[s]){
            s++;
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}