#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100000+5],s1,s2,ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    memset(a,1e9,100000+5);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    ans=n;
    s2=(upper_bound(a+1,a+n+1,a[1])-a)-(lower_bound(a+1,a+n+1,a[1])-a);
    for(int i=1;i<n;i+=s1){
        s1=s2;
        if(i+s1<=n)s2=(upper_bound(a+1,a+n+1,a[i+s1])-a)-(lower_bound(a+1,a+n+1,a[i+s1])-a);
        else break;
        ans-=min(int(s1),int(s2));
        if(s1>s2){
            s2+=s1-s2;
        }
    }
    cout<<ans<<endl;

    return 0;
}
