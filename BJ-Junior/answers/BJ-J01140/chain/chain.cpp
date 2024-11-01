#include<bits/stdc++.h>
using namespace std;
struct ll{
    long long a[20005];
};
ll s[10005];
bool Find(int x,int y){
    for(int i=1;i<=200000;i++)
        if(s[x].a[i]==y) return true;
    return false;
}
int Findnum(int x,int y){
    for(int i=1;i<=200000;i++)
        if(s[x].a[i]==y) return i;
}
int Go(int x,int n,int y,int k,int r){
    if(r==0) return 1;
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        for(int j=0;j<=k;j++){
            if(k-j<1) break;
            if(Find(i,s[x].a[k-j]))
            return Go(i,n,Findnum(i,s[x].a[k-j]),k,r-1);
        }
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++) cin>>s[i].a[j];
        }
        while(q--){
            int r,c,ans=0;
            cin>>r>>c;
            for(int i=1;i<=n;i++){
                if(Find(i,c))
                ans=Go(i,n,Findnum(i,c),k,r);
                if(ans==1) break;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
