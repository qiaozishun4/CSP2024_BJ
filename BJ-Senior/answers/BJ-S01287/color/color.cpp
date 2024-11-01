#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],f[100005][2],b[20005],r[20005],cnt,sum;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        if(n<=28){
        sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=0;i<(1<<n);i++){
            sum=0;
            for(int j=0;j<n;j++){

                if(i&(1<<j)){

                    b[j+1]=a[j+1];
                    if(b[j]==a[j+1]){
                        sum+=a[j+1];

                    }
                    r[j+1]=r[j];
                }
                else{

                    r[j+1]=a[j+1];
                    if(r[j]==a[j+1]){
                        sum+=a[j+1];

                    }
                    b[j+1]=b[j];
                }
            }
            cnt=max(cnt,sum);
        }
        cout<<cnt<<endl;
        cnt=0;
        }
        if(n>20){
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            f[i][0]=0;
            f[i][1]=0;
            for(int j=1;j<=i;j++){
                if(a[i]==a[j]&&i!=j){
                    f[i][0]=max(f[i][0],r[i-1]+a[i]);
                    f[i][1]=max(f[i][1],b[i-1]+a[i]);
                }
                else{
                    f[i][0]=max(f[i][0],r[j-1]);
                    f[i][1]=max(f[i][1],b[j-1]);
                }

                b[j]=max(b[j-1],f[j][0]);
                r[j]=max(r[j-1],f[j][1]);
            }
            cout<<f[i][0]<<' '<<f[i][1]<<endl;
            cnt=max(cnt,max(f[i][0],f[i][1]));
        }
        cout<<cnt<<endl;
        }
    }
}
