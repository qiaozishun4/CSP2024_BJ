#include <bits/stdc++.h>
using namespace std;
int T,n,nmin[10005],nminn,nminf=0;
int ndp[7]={8,0,6,2,4,7,1};
int ndphv[7]={7,6,6,5,4,3,2};
int a[10005];
void dfs(int stk,int stp){
    if(stk==0){
        if(nminf=0 || nminn>stp){
            for(int i=1;i<=10001;i++) nmin[i]=0;
            nminn=stp;
            for(int i=1;i<=stp;i++) nmin[i]=a[i];
            nminf=1;
            return ;
        }
        for(int i=stp;i>=1;i--){
            if(a[i]<nmin[i] || nmin[stp]==0){
                for(int i=1;i<=10001;i++) nmin[i]=0;
                nminn=stp;
                for(int i=1;i<=stp;i++) nmin[i]=a[i];
                return ;
            }
            if(a[i]>nmin[i]) return;
        }
        return;
    }
    if(nminn<stp) return ;
    for(int i=0;i<7;i++){
        if(n>=ndphv[i]){
            n-=ndphv[i];
            a[stp+1]=ndp[i];
        }
        else continue;
        dfs(n,stp+1);
        a[stp]=0;
        n+=ndphv[i];
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    for(int i=1;i<=10001;i++) nmin[i]=10;
    for(int i=1;i<=T;i++){
        cin>>n;
        if(n%7==0){
            for(int i=1;i<=n/7;i++) cout<<8;
            cout<<endl;
            nminn=0;
            nminf=0;
            continue;
        }
        dfs(n,0);
        if(nminn==0) cout<<-1<<endl;
        else{
            for(int i=nminn;i>=1;i--) cout<<nmin[i];
            for(int i=1;i<=10001;i++) nmin[i]=10;
            cout<<endl;
        }
        nminn=0;
        nminf=0;
    }
}