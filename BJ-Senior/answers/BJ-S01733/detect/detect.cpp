#include <bits/stdc++.h>
using namespace std;
int t,n,m,l,vx,k,num,s;
int d[100005],v[100005],a[100005],p[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for (int i=1;i<=t;i++){
        cin>>n>>m>>l>>vx;
        for (int j=0;j<n;j++){
            cin>>d[j]>>v[j]>>a[j];
        }
        for (int j=0;j<m;j++){
            cin>>p[j];
        }

        for (int j=0;j<n;j++){
            k=0;
            while ((d[j]+v[j]*k+a[j]*k*k<l) && (d[j]+v[j]*k+a[j]*k*k>0)){
                k++;
            }

            if (a>0){
                if (v[j]<vx){
                    int s=(vx-v[j])/a[j]+1;
                    for (int h=0;h<m;h++){
                        if ((v[j]+a[j]*s)*s<p[m] && (v[j]+a[j]*k)*k>=p[m]){
                            num++;
                            break;
                        }
                    }
                }
            }
            if (a==0){
                if (v[j]>vx){
                    num++;
                    break;
                }
            }
            if (a>0){
                if (v[j]>vx){
                    int s=(vx-v[j])/a[j]+1;
                    for (int h=0;h<m;h++){
                        if ((v[j]+a[j]*s)*s>p[m] && (v[j]+a[j]*k)*k>=p[m]){
                            num++;
                            break;
                        }
                    }
                }
            }
        }

    }
    cout<<num<<" "<<m-num<<endl;
    return 0;
}
