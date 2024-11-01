#include<bits/stdc++.h>
using namespace std;
    int aa1[100005];
    int c[100005];
    int a1[100005];
    int win[100005];
        string s[100005];
    int ans[100005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>aa1[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    for(int i=log2(n);i>=1;i--)cin>>s[i];
    int t;cin>>t;
    while(t--){

        int x[4];cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)a1[i]=aa1[i]^x[i%4];
            for(int i=1;i<=log2(n);i++){
                    for(int j=1;j<=pow(2,i);j++)win[j]=j;
                for(int j=i;j>=1;j--){
                    for(int k=1;k<=pow(2,j);k+=2){
                        if(s[j][k]=='1'){
                            if(a1[win[k+1]]>=i-j+1)win[k/2+1]=win[k+1];
                            else win[k/2+1]=win[k];
                        }else{
                            if(a1[win[k]]>=i-j+1)win[k/2+1]=win[k];
                            else win[k/2+1]=win[k+1];
                        }
                    }
                }
                ans[i]=win[1];
            }
            int kans=0;
            for(int i=1;i<=m;i++)kans=kans+ans[(int)log2(c[i])];
            cout<<kans;

    }
}
