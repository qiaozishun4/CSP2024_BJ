#include<bits/stdc++.h>
using namespace std;
int n,s,maxn=0,ans;
int a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]>maxn){
            maxn=a[i];
            s++;
            b[s]++;
        }
        else{
            b[s]++;
        }
    }
    for(int i=1;i<=s;i++){
        ans-=min(ans,b[i]);
        ans+=b[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
