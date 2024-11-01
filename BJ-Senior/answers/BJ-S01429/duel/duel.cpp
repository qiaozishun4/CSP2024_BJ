#include<bits/stdc++.h>
using namespace std;
int a[100005],atkd[100005],n,ans=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int x=2;
    for(int i=1;i<=n;i++){
        if(x==0)ans++;
        else{
            atkd[x]=1;
            while(atkd[x] || a[x]<=a[i]){
                x++;
                if(x>n){
                    x=0;
                    ans++;
                    break;
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
// The password of CSP-J is normal, so he wants me to be a normal person
// The password of CSP-S is astro, so he wants me to be an astronaut
// Is my guess correct?