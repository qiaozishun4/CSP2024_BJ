#include <iostream>
#include <algorithm>
using namespace std;
int T;
int tong[2005],n,a[2005];
long long sum;
int c;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        sum=0;
        for(int i=1;i<=n;i++){
            cin>>c;
            tong[c]++;
        }
        for(int i=1;i<=2000;i++){
            if(tong[i]>=2){
                sum+=(tong[i]-1)*i;
                cout<<i<<" ";
            }
            tong[i]=0;
        }
        cout<<sum<<endl;
    }
    return 0;




}