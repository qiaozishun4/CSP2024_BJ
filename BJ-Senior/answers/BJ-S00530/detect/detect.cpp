#include<bits/stdc++.h>
using namespace std;
const int INF=1e5+1;
long long ans=0;
long long det[INF],car[INF][4];//,che[INF];
bool bS(int a,double b,int m){
    int l=1,r=m;
    int flag1=0,flag2=0;
    if(a>det[m])return 0;
    if(b<det[1])return 0;
    while(l<r){
        int mid=(l+r)/2;
        if(det[mid]>=a)r=mid;
        else l=mid+1;
    }
    //cout<<"l:"<<l<<" ";
    flag1=l;
    l=1,r=m;
    while(l<r){
        int mid=(l+r+1)/2;
        if(det[mid]>=b)r=mid-1;
        else l=mid;
    }
    //cout<<"r:"<<r<<" ";
    flag2=r;
    if(flag1<=flag2)return 1;
    return 0;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    long long T,n,m,L,V;
    scanf("%lld",&T);
    for(int k=1;k<=T;k++){
            ans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        //for(int i=1;i<=m;i++)che[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%lld%lld%lld",&car[i][1],&car[i][2],&car[i][3]);
        }
        for(int i=1;i<=m;i++){
            scanf("%lld",&det[i]);
        }
        long long cnt=0;
        for(int i=1;i<=n;i++){
            if(car[i][3]>0){
                double maxs=car[i][1]+(V*V-car[i][2]*car[i][2])/2.0/car[i][3];
                /*for(int j=1;j<=m;j++){
                    if(det[j]>maxs)che[j]++;
                }*/
                if(det[m]>maxs&&car[i][1]<=det[m])cnt++;
            }else if(car[i][3]==0){
                if(car[i][2]<=V)continue;
                else{
                    /*for(int j=1;j<=m;j++){
                        if(det[j]>=car[i][1])che[j]++;
                    }*/
                    if(car[i][1]<=det[m])cnt++;
                }
            }else{
                if(car[i][2]<=V)continue;
                double maxs=car[i][1]+(V*V-car[i][2]*car[i][2])/2.0/car[i][3];
                //cout<<"maxs:"<<maxs<<" ";
                /*for(int j=1;j<=n;j++){
                    if(det[j]>=car[j][1]&&det[j]<maxs)che[j]++;
                }*/
                if(bS(car[i][1],maxs,m)){
                    cnt++;
                }
            }
            /*for(int j=1;j<=m;j++){
                cout<<che[j]<<" ";
            }
            cout<<endl;*/
        }
        printf("%lld ",cnt);
        for(int l=1;l<=m;l++){
            long long tmp=det[l];
            det[l]=-1*INF;
            long long cnt1=0;
        for(int i=1;i<=n;i++){
            if(car[i][3]>0){
                double maxs=car[i][1]+(V*V-car[i][2]*car[i][2])/2.0/car[i][3];
                /*for(int j=1;j<=m;j++){
                    if(det[j]>maxs)che[j]++;
                }*/
                if(det[m]>maxs&&car[i][1]<=det[m])cnt++;
            }else if(car[i][3]==0){
                if(car[i][2]<=V)continue;
                else{
                    /*for(int j=1;j<=m;j++){
                        if(det[j]>=car[i][1])che[j]++;
                    }*/
                    if(car[i][1]<=det[m])cnt1++;
                }
            }else{
                if(car[i][2]<=V)continue;
                double maxs=car[i][1]+(V*V-car[i][2]*car[i][2])/2.0/car[i][3];
                //cout<<"maxs:"<<maxs<<" ";
                /*for(int j=1;j<=n;j++){
                    if(det[j]>=car[j][1]&&det[j]<maxs)che[j]++;
                }*/
                if(bS(car[i][1],maxs,m)){
                    cnt1++;
                }
            }
            /*for(int j=1;j<=m;j++){
                cout<<che[j]<<" ";
            }
            cout<<endl;*/
        }
        if(cnt1==cnt)ans++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
