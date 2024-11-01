#include <iostream>

using namespace std;
int a[200000];
int main()
{
    freopen("color.in","r",stdin);
 freopen("color.out","w",stdout);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        if(n>=31){
            int ma=0;
            for(int i=0;i<n;i++){
                ma=max(ma,a[i]);

            }
            int k=0;
            for(int i=0;i<n;i++){
                if(a[i]==   ma){
                    k++;
                }
            }
            cout<<(k-1)*ma<<endl;
            continue;
        }
        int ans=0;
        for(int      i=0;i<(1<<n);i++){
            int x=0,y=0,k=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    if(x==a[j])k+=a[j];
                    x=a[j];
                }else{
                    if(y==a[j])k+=a[j];
                    y=a[j];
                }
            }ans=max(ans,k);
        }
        cout<<ans<<endl;
    }
fclose(stdin);
    fclose(stdout);
    return 0;
}
