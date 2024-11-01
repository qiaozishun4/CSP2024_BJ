#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        int n,a[200005],v[1000005],k[1000005],sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
//        for(int i=1;i<=n;i++){
//            if(v[a[i]]==2){
//                if(i-k[a[i]]<=2){
//                    sum+=a[i];
//                    v[a[i]]=0;
//                    k[a[i]]=0;
//                }
//            }
//            v[a[i]]++;
//            k[a[i]]=i;
//        }
       cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
