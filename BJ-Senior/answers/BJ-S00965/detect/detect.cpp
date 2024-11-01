#include<bits/stdc++.h>
using namespace std;
const int N = 10000002;
int d[N],v[N],a[N],p[N];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",);
    int t;
    cin>>t;
    while(t--){
        int n,m,l,V,flag = 1,f2 = 1;
        cin>>n>>m>>l>>V;
        for(int i = 0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]<0){
                flag = 0;
            }
        }
        for(int i = 0;i<n;i++){
            cin>>p[i];
        }
        if(flag){
            int ans = 0;
            for(int i = 0;i<n;i++){
                if(a==0){
                    if(v[i]>V){
                        ans++;
                    }
                }else if((V*V-v[i]*v[i]) / (2*a[i])+d[i] < p[m]){
                    ans++;
                }
            }
            cout<<ans<<' ';
            if(ans!=0){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            }
            return 0;
        }
        int flb = 0,fls = 0,fle =0;
        for(int i = 0;i<n;i++){
            if(a==0){
                if(v[i]>V){
                    fle = 1;
                }
            }else if(a>0){
                if((V*V-v[i]*v[i]) / (2*a[i])+d[i] < p[m]){
                    flb = 1;
                    ans++;
                }
            }else if(a<0){
                if((V*V-v[i]*v[i]) / (2*a[i])+d[i] < p[m]){
                    fls = 1;
                    ans++;
                }
            }
            cout<<ans<<' ';
        }
        cout<<ans<<' ';
        if(flb == 0 && fls == 0){
            cout<<fle<<endl;
        }else{
            cout<<fb+fls<<endl;
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}