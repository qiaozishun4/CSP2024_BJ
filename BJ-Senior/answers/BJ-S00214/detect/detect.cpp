#include<bits/stdc++.h>
using namespace std;
int n,m,L,V,t,d[100002],u[100002],a[100002],c[100002],cnt,csd,nn[100002],ans;
int main(){
	freopen("r","detect.in",stdin);
	freopen("w","detect.out",stdout);
    cin>>t;
    for(int o=1;o<=t;o++){
        cnt=0;
        ans=0;
for(int i=1;i<=m;i++) nn[i]=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>u[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>c[i];
        }
        for(int i=1;i<=n;i++){
			if(a[i]!=0)
                csd=floor((((V*V)-(u[i]*u[i]))*1.0)/((2*a[i])*1.0))+d[i];
            else if(u[i]>V)
                csd=d[i];
            else
                csd=99999;
            for(int j=1;j<=m;j++){
                if(a[i]>=0&&c[j]>csd&&c[j]>=d[i]){
                    cnt++;
                    nn[j]=c[j];
                    break;
                }
                else if(a[i]<0&&c[j]<csd&&c[j]<csd&&c[j]>=d[i]){
                    cnt++;
                    nn[j]=c[j];
                    break;
                }
            }
        }
        cout<<cnt<<" ";
        for(int i=1;i<=m;i++){
            if(nn[i]!=c[i]){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;

}

