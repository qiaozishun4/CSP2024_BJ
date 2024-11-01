#include<iostream>
#include<cstdio>
using namespace std;
int t,n[11],a[11][100001],dp[11][100001];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n[i];
        for(int j=1;j<=n[i];j++)cin>>a[i][j];
    }

    for(int i=0;i<t;i++){
        int mx=-1;
        for(int j=1;j<=n[i];j++)mx=max(mx,a[i][j]);
        bool b[100001]={false};
        dp[i][1]=0;b[1]=true;
        if(a[i][1]==a[i][2])b[2]=true;
        else b[2]=false;
        if(b[2]==true)dp[i][2]=a[i][2];
        else dp[i][2]=0;
        b[3]=true;int c0=0;
        int i0[100001]={0};
        for(int k=1;k<=n[i];k++){
            i0[a[i][k]]++;
        }for(int i=1;i<=mx;i++){
            c0+=max(0,i*(i0[i]-1));
        }
        cout<<c0<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}