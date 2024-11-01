#include<bits/stdc++.h>
using namespace std;
int n,a[250000],maxa;
int r[25000],b[25000];
int T;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        maxa=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int x=0;x<(1<<n);x++){
            // cout<<"x:"<<x<<endl;
            int rtop=0,btop=0;
            for(int i=0;i<n;i++){
                if(x&(1<<i)){
                    r[++rtop]=i+1;
                }else{
                    b[++btop]=i+1;
                }
                // cout<<rtop<<" "<<btop<<endl;
            }
            // cout<<"r";
            // for(int i=1;i<=rtop;i++){
            //     cout<<r[i]<<" ";
            // }
            // // cout<<endl<<"b";
            // for(int i=1;i<=btop;i++){
            //     // cout<<b[i]<<" ";
            // }
            // cout<<endl;
            int sum=0,rl=0,bl=0;
            for(int i=1;i<=rtop;i++){
                if(a[r[i]]==rl) sum+=a[r[i]];
                rl=a[r[i]];
            }
            // cout<<"rok\n";
            for(int i=1;i<=btop;i++){
                if(a[b[i]]==bl) sum+=a[b[i]];
                bl=a[b[i]];
            }
            // cout<<"bok\n";
            // cout<<sum<<endl;
            maxa=max(maxa,sum);
        }
        cout<<maxa<<endl;
    }
    return 0;
}