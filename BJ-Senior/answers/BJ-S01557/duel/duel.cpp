#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[100010];
long long b[100010];
bool flag=false;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[a[i]]++;
        if(b[a[i]]>1){
            flag=true;
        }
    }
    if(!flag){
     cout<<1;
        return 0;
    }
    for(int i=1;i<=n-1;i++){
        for(int j=i;j<=n;j++){
            if(a[j]>a[i]&&a[i]!=-1&&a[i]!=-2&&a[j]!=-2){//如果强的没有被打死并且没有出手过并且弱的没被打就打
              //  cout<<"a[j]:"<<a[j]<<" a[i]:"<<a[i]<<endl;
                a[i]=-1;//被打了
                a[j]=-2;//打过了

            }
            if(a[i]>a[j]&&a[i]!=-1&&a[i]!=-2&&a[j]!=-1){
               // cout<<"a[i]:"<<a[i]<<" a[j]:"<<a[j]<<endl;
                a[j]=-1;
                a[i]=-2;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=-1){
            ans++;
       //     cout<<a[i]<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
