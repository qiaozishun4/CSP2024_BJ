#include<bits/stdc++.h>
using namespace std;
int T,n,s,x,maxn=0;
int a[2005],c[2005],pot[2005],t[2005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        s=0;
        for(int i=1;i<=2005;i++){
            t[i]=0;
        }
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            t[a[i]]++;
        }
        for(int i=1;i<=2005;i++){
            if(t[i]>=2){
                s+=i;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
