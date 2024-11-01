#include<bits/stdc++.h>
using namespace std;
const long long N=1000100;
long long a[N],c[N],w[N];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long x,n,cnt=0,s1=0,s2=0,s3=0,s4=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
            cin>>x;
            cnt=0;
        for(long long j=1;j<=x;j++){
            cin>>a[j];
        }
        for(long long j=1;j<=x;j++){
            for(long long k=j+1;k<=x;k++){
                if(a[j]==a[k]){
                    cnt+=a[j];
                    w[j]=1;
                    w[k]=1;
                    s1=s2;
                    s3=s4;
                    s2=j;
                    s4=k;
                    break;
                }
                if(a[s1]>a[s2]&&s1<s2&&s3>s4){
                    cnt-=a[s2];
                }
            }
        }
    cout<<cnt<<endl;
    }
    return 0;
}
