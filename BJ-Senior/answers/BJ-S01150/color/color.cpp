#include<bits/stdc++.h>
using namespace std;
int a[100000],b[100000];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t,op;
    cin>>op;
    for(t=0;t<op;t++){
        memset(a,0,sizeof(a));
        int i,j,k,mx=0,s,n;
        cin>>n;
        for(i=0;i<n;i++)cin>>a[i];
        for(i=0;i<pow(2,n);i++){
            memset(b,0,sizeof(b));
                int o=i;s=0;
            for(j=0;o;j++){
                b[j]=o&1;o>>=2;
            }
            for(j=0;j<n;j++){
                for(k=j-1;k>=0;k--){
                    if(b[j]==b[k]){
                    if(a[j]==a[k])s+=a[k];}
                    else break;
                }//cout<<s<<' ';
            }if(mx<s)mx=s;
        }cout<<mx<<endl;
    }
}
