#include<bits/stdc++.h>
using namespace std;
bool a[200005];
int a1[200005];
int c[200005];
int ans[15];
void f(int n,int x){
    bool flag=true;
    for(int i=n;i>1;i--){
        for(int j=i;j>0;j--){
            if(a1[j]==a1[i]){
                a[i]=flag;
                a[j]=flag;
                !(flag);
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i-1;j>0;j--){
            if(!(a[i]^a[j])){
                c[i]=a1[i];
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=c[i];
    }
    memset(a,200005,sizeof(a));
    memset(a1,200005,sizeof(a));
    memset(c,200005,sizeof(a));
    ans[x]=sum;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        f(n,i);
    }
    for(int i=0;i<t;i++){
        cout<<ans[i];
    }
    return 0;
}
