

#include<bits/stdc++.h>
using namespace std;
struct node{
    long long x,y,z;
}a[100009];
long long b[100009];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        long long n,m,l,v,mx=INT_MIN;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
            mx=max(b[i],mx);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].x>mx) continue;
            if((a[i].x-mx)*a[i].z+a[i].y>v) ans++;
        }
        if(ans==0) m++;
        cout<<ans<<" "<<m-1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
