#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,mx=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>mx){
            mx=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        b[a[i]]++;
    }
    int st=1;
    for(int i=2;i<=mx;i++){
        int m=b[i];
        for(int j=st;j<i;j++){
            if(m==0){
                break;
            }
            if(m>=b[j]){
                m-=b[j];
                b[j]=0;
                st++;
            }else{
                b[j]-=m;
                m=0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=mx;i++){
        ans+=b[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
