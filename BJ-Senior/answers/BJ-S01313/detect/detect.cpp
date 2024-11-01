#include<bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],m[100005],an[100005],mdl[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,mn,l,vx,md=0;
        cin>>n>>mn>>l>>vx;
        for(int j=1;j<=n;j++){
            cin>>d[j]>>v[j]>>a[j];
            if(a[j]==0&&(md==0||md==1)){
                md=1;
            }else if(a[j]>0&&(md==0||md==2)){
                md=2;
            }else if(a[j]<0&&(md==0||md==3)){
                md=3;
            }else{
                md=4;
            }
        }
        for(int j=1;j<=mn;j++){
            cin>>m[j];
        }
        if(md==1){
            int ans=0;
            for(int j=1;j<=n;j++){
                if(v[j]>vx&&d[j]<=m[mn]){
                    ans++;
                }
            }
            cout<<ans<<' ';
            if(ans==0){
                cout<<mn<<endl;
            }else{
                cout<<mn-1<<endl;
            }
            continue;
        }
        if(md==2){
            int ans=0;
            for(int j=1;j<=n;j++){
                if(v[j]>vx&&d[j]<=m[mn]){
                    ans++;
                    continue;
                }
                if(d[j]>m[mn]){
                    continue;
                }
                int dx=m[mn]-d[j];
                int vt=sqrt(v[j]*v[j]+(2*a[j]*dx));
                if(vt>vx){
                    ans++;
                }else{
                }
            }
            cout<<ans<<' ';
            if(ans==0){
                cout<<mn<<endl;
            }else{
                cout<<mn-1<<endl;
            }
        }
        if(md==3&&md==4){
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
