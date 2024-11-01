#include <bits/stdc++.h>
using namespace std;
int s[100050][3],c[100050];
int erfen(int x,int n){
    int l=1,r=n;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(c[mid]>=x){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int s1=1;s1<=t;s1++){
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int xs=1;xs<=n;xs++){
            cin>>s[xs][0]>>s[xs][1]>>s[xs][2];
        }
        for(int xs=1;xs<=m;xs++)cin>>c[xs];
        int ans1=0;
        for(int xs=1;xs<=n;xs++){
            double speed;
            int d;
            if(s[xs][2]>0){
                d=c[m]-s[xs][0];
            }else{
                d=c[erfen(s[xs][0],m)]-s[xs][0];
            }
            speed=sqrt(s[xs][1]*s[xs][1]+2*d*s[xs][2]);
            if(speed>v){
                ans1++;
            }
        }
        cout<<ans1<<" "<<n-1<<endl;;
    }
    return 0;
}
