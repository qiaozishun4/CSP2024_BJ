#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V,d[100001],v[100001],a[100001],ov[100001][3],ans1,detected[100001],detector[100001],ans2;
double tmp;
int main(){
    memset(ov,-1,sizeof(ov));
    //*
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    //*/
    cin>>T;
    while(T!=0){
        T--;
        cin>>n>>m>>L>>V;
        ans1=0;
        ans2=m;
        for(int i=0;i<n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(v[i]<=V&&a[i]<=0){
                continue;
            }
            else if(v[i]>=V&&a[i]>=0){
                ov[i][0]=d[i];
                ov[i][1]=L;
            }
            else if(v[i]>V&&a[i]<0){
                ov[i][0]=d[i];
                tmp=(V*V-v[i]*v[i])*0.5/a[i];
                ov[i][1]=d[i]+floor(tmp);
                if(ov[i][1]>L){
                    ov[i][1]=L;
                }
            }
            else if(v[i]<V&&a[i]>0){
                tmp=(V*V-v[i]*v[i])*0.5/a[i];
                ov[i][0]=d[i]+floor(tmp);
                if(ov[i][0]>L){
                    ov[i][0]=-1;
                }
                ov[i][1]=L;
            }
        }
        for(int i=0;i<m;i++){
            cin>>detector[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m&&detector[j]<=ov[i][1];j++){
                if(detector[j]>=ov[i][0]&&ov[i][0]!=-1){
                    detected[j]++;
                    ov[i][2]=1;
                }
            }
            if(ov[i][2]==1){
                ans1++;
            }
        }
        cout<<ans1<<' ';
        if(m==1){
            if(detected[0]==0){
                cout<<1<<endl;
                continue;
            }
            else{
                cout<<0<<endl;
                continue;
            }
        }
        for(int i=0;i<m;i++){
            if(i==0){
                if(detected[i]>detected[i+1]){
                    ans2--;
                }
            }
            else if(i==m-1){
                if(detected[i]>detected[i-1]){
                    ans2--;
                }
            }
            else {
                if(detected[i]>=detected[i-1]&&detected[i]>=detected[i+1]){
                    ans2--;
                }
            }
        }
        cout<<ans2<<endl;
    }
    return 0;
}
