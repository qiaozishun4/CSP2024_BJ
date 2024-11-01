#include <bits/stdc++.h>
using namespace std;
long long a[100005][3];
long long b[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    long long T;
    long long n,m,l,v;
    long long op = 0;
    long long cnt = 0;
    long long ans = 0;
    long long dx;
    cin>>T;
    for(int o=0;o<T;o++){
        cin>>n>>m>>l>>v;
        ans = 0;
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][2]>0){
                if(op==0){
                    op = 3;
                }
                cnt++;
            }
            else if(a[i][2]<0){
                if(op==0){
                    op = 3;
                }
                cnt--;
            }
        }
        if(cnt==n){
            op = 1;
        }
        if(cnt==-n){
            op = 2;
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
        }
        if(op==0){
            for(int i=0;i<n;i++){
                if(a[i][0]<=b[m]&&a[i][1]>v){
                    ans++;cout<<ans<<" ";
            if(m==1){
                if(ans!=0){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
            else{
                if(ans!=0){
                    cout<<m-1<<endl;
                }
                else{
                    cout<<m<<endl;
                }
            }
                }
            }
            cout<<ans<<" ";
            if(m==1){
                if(ans!=0){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
            else{
                if(ans!=0){
                    cout<<m-1<<endl;
                }
                else{
                    cout<<m<<endl;
                }
            }
        }
        else if(op==1){
            for(int i=0;i<n;i++){
                if(a[i][0]<=b[m]&&(a[i][1]*a[i][1]+2*a[i][2]*(b[m]-a[i][0]))>v*v){
                    ans++;
                }
            }
            cout<<ans<<" ";
            if(m==1){
                if(ans!=0){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
            else{
                if(ans!=0){
                    cout<<m-1<<endl;
                }
                else{
                    cout<<m<<endl;
                }
            }
        }
    }
    return 0;
}