#include<bits/stdc++.h>
//图灵保佑我暴力枚举能过！！！
using namespace std;
bool a[10000];
int b[10000],T,n;
long long f(bool is,int x){
    long long ans=0;
    a[x]=is;
    if(x==0){
        int flag=0;
        for(int k=n;k>=1;k--){
            if(a[k]){
                if(b[k]==flag)ans+=b[k];
                else flag=b[k];
            }
        }
        flag=0;
        for(int k=n;k>=1;k--){
            if(a[k]==false){
                if(b[k]==flag)ans+=b[k];
                else flag=b[k];
            }
        }
        return ans;
    }
    return max(f(true,x-1),f(false,x-1));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n;
        for(int j=1;j<=n;j++){
            cin>>b[j];
        }
        cout<<f(true,n-1)<<endl;
    }
    return 0;
}
