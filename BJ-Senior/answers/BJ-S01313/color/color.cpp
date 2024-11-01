#include<bits/stdc++.h>
using namespace std;
int q[1000005][15];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        int p=pow(2,n);
        for(int j=0;j<p;j++){
            for(int k=0;k<n;k++){
                q[j][n-k-1]=(j/int(pow(2,k)))%2;
            }
        }
        int mxans=0;
        for(int j=0;j<p;j++){
            int rd=-1,bl=-1,ans=0;
            for(int k=0;k<n;k++){
                if(q[j][k]==0){
                    if(rd==-1){
                        rd=k;
                        continue;
                    }
                    if(a[rd]==a[k]){
                        ans+=a[k];
                    }
                    rd=k;
                }
                if(q[j][k]==1){
                    if(bl==-1){
                        bl=k;
                        continue;
                    }
                    if(a[bl]==a[k]){
                        ans+=a[k];
                    }
                    bl=k;
                }
            }
            if(ans>mxans){
                mxans=ans;
            }
        }
        cout<<mxans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
