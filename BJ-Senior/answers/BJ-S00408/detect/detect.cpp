#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t,n[25],m[25],l[25],v[25],di[25][100005],vi[25][100005],ai[25][100005],mi[25][100005],ans1[25]={0},ans2[25]={0};
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>n[i]>>m[i]>>l[i]>>v[i];
        for(int j=1;j<=n[i];j++)
            cin>>di[i][j]>>vi[i][j]>>ai[i][j];
        for(int j=1;j<=m[i];j++)
            cin>>mi[i][j];
    }
    for(int i=1;i<=t;i++){
        int mmax=0;
        ans2[i]=m[i]-1;
        for(int j=1;j<=m[i];j++)
            if(mi[i][j]>mmax) mmax=mi[i][j];
        for(int j=1;j<=n[i];j++)
            if(di[i][j]<=mmax && vi[i][j]>v[i]) ans1[i]++;
    }
    for(int i=1;i<=t;i++)
        cout<<ans1[i]<<" "<<ans2[i]<<endl;
    fclose(stdin);
    fclose(stdout);
return 0;
}