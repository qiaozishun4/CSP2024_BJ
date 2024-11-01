#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int s=-1;//1-A 2-B 3-C
    int T;
    int L,V;
    int n,m;
    int d[100005],v[100005],a[100005];
    int lc[100005];
    cin>>T;
    int maxlc=-1;
    for(int k=1;k<=T;k++){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(i==1){
                if(a[i]==0){
                    s=1;
                }else if(a[i]>0){
                    s=2;
                }else{
                    s=3;
                }
            }
            if(i>=2){
                if((s==1&&a[i]!=0)||(s==2&&a[i]<=0)||(s==3&&a[i]>=0)){
                    cout<<"no"<<endl;
                    return 0;
                }
            }
        }
        for(int i=1;i<=m;i++){
            cin>>lc[i];
        }
        //cout<<s<<endl;
        sort(lc+1,lc+m+1);
        if(s==1){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(v[i]>V&&d[i]<=lc[m]){
                    cnt++;
                }
            }
            if(cnt==0){
                cout<<cnt<<" "<<m<<endl;
            }else{
                cout<<cnt<<" "<<max((m-1),0)<<endl;
            }

        }

        if(s==2){
            int cnt=0;
            int sc=9999999;
            for(int i=1;i<=n;i++){
                if(v[i]>V){
                    cnt++;
                    continue;
                }
                long long vc=v[i]*v[i]+2*a[i]*(-d[i]+lc[m]);
                if(vc>V*V){
                    cnt++;
                    sc=min(sc,(V*V-v[i]*v[i])/(2*a[i])+1+d[i]);
                }
            }
            if(cnt==0){
                cout<<"0"<<" "<<m<<endl;
                return 0;
            }
            int cnt2=m;
            for(int i=1;i<=m;i++){
                if(lc[i]>=sc&&lc[i]>d[i]){
                    break;
                }else{
                    cnt2--;
                }
            }
            cout<<cnt<<" "<<cnt2<<endl;
        }
        if(s==3){
            int cnt=0;
            int sc=-1;
            for(int i=1;i<=n;i++){
                if(v[i]<=V){
                    continue;
                }else{
                    int vc=v[i]*v[i]+2*a[i]*(d[i]+lc[1]);
                    if(vc>V*V){
                        cnt++;
                        sc=max(sc,(V*V-v[i]*v[i])/(2*a[i])+1-d[i]);
                    }
                }
            }
            if(cnt==0){
                cout<<"0"<<" "<<m<<endl;
            }else{
                for(int i=m;i>=1;i--){
                    if(lc[i]<sc){
                        break;
                    }else{
                        m--;
                    }
                }
                cout<<cnt<<" "<<m<<endl;
            }
        }
    }
    return 0;
}
