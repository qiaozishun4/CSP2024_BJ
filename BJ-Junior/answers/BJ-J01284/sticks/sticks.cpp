#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long f[100010];
int a[20]={6,2,5,5,4,5,6,3,7,6},b[100010];
void x(int v){
    int cnt=0,cn=0;
    while(v){
        if(v/10!=0&&a[v%10]==6)cnt++;
        else if(v/10!=0)b[++cn]=v%10;
        else if(v/10==0){
            cn+=cnt;
            b[++cn]=v%10;
        }
        v/=10;
    }
    for(int i=cn;i>=1;i--){
        cout<<b[i];
    }
    cout<<endl;
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            f[i]=1e9;
        }
        f[0]=0;
        for(int i=1;i<10;i++){
            for(int j=a[i];j<=n;j++){
                f[j]=min(f[j],f[j-a[i]]*10+i);
            }
        }
        if(f[n]==1e9)cout<<-1<<"\n";
        else x(f[n]);
    }
    return 0;
}
