#include<bits/stdc++.h>
using namespace std;
int d[100010],v[100005],a[100005],p[1000005],f[1000005],ans;
int main(){
//    freopen("detect.in","r",stdin);
//    freopen("detect.out","w",stdout);
    int T,n,m,l,V,x,i,j,k,b,ff=0;
    cin>>T;
    for(i=1;i<=T;i++){
        cin>>n>>m>>l>>V;
        for(j=1;j<=n;j++)
            cin>>d[j]>>v[j]>>a[j];
        for(j=1;j<=m;j++){
            cin>>x;
            p[x]=1;
        }


        for(j=1;j<=n;j++){
            if(a[j]<=0){
 //               cout<<d[j]<<" "<<v[j]<<" "<<a[j]<<endl;
                for(k=d[j];k<=l;k++){
                    if(p[k]==1) break;
                }
                if(k==l+1) continue;
//                cout<<k<<" ";
                int z=v[j]*v[j]+2*a[j]*(k-d[j]);
//                cout<<z<<endl;
                for( b=1;b*b<=z;b++)
                    x=0;
                int sd=b-1;
                if(sd*sd==z) sd--;
                if(sd>=V){
                    ans++;
                    f[k]=1;
                }
            }
            if(a[j]>0){
                if(v[j]>=V)
                    for(k=d[j];k<=l;k++){
                        if(p[k]==1){
                            f[k]=1;
                            ans++;
                            break;
                        }
                    }
                else{
                    int z=d[j]+(V*V-v[j]*v[j])/(2*a[j]);
                    for(k=z+1;k<=l;k++)
                        if(p[k]==1){
                            ans++;
                            f[k]==1;
                            break;
                        }
  //                      cout<<k;
                }
            }
        }
 //       for(j=0;j<=l;j++) cout<<f[j]<<endl;
        cout<<ans<<" ";
        int y=0;
        for(j=0;j<=l;j++) if(f[j]==1) y++;
        cout<<m-y<<endl;
        for(j=1;j<=l;j++){
            p[j]=0;
            f[j]=0;
        }
        ans=0;
    }

    return 0;
}
