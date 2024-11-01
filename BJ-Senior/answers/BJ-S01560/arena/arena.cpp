#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int n,m,t;
    cin>>n>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>c[i];
    int Kans=1,K=0;
    while(Kans<n)Kans*=2,K++;
    for(int i=1;i<=K;i++){
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)d[i][j]=s[j]-'0';
    }cin>>t;
    while(t--){
        int x[5];
        for(int i=0;i<=3;i++){
            cin>>x[i];
            b[i]=a[i]^x[i]%4;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
