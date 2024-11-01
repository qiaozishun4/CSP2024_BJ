#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        long long sum=0;
        long long a[200001];
        long long c[200001];
        cin>>n;
        for(long long i=1;i<=n;i++){
            c[i]=0;
        }
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        for(long long i=1;i<=n;i++){
            bool f=false;
            for(long long j=i-1;j>=1;j--){
                if(a[i]==a[j]){
                    if(!f){
                        c[i]=1;
                        long long csum=0;
                        for(long long k=i-1;k>=j+1;k--){
                            if(c[k]==1){
                                csum+=a[k];
                            }
                        }
                        if(a[i]>csum){
                            sum-=csum;
                            sum+=a[i];
                        }
                        else{
                            c[i]=0;
                        }
                        f=true;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
