#include <bits/stdc++.h>

using namespace std;
int T,n,a[200005],b[200005];
int  baoli(int lun){
    if(lun==n){
        int ans=0,cl=0,dl=0,c[25]={},d[25]={};
        for(int i=0;i<n;i++){
            if(b[i]==1){
                c[cl]=a[i];
                cl++;
            }
            else{
                d[dl]=a[i];
                dl++;
            }
        }
        for(int i=1;i<cl;i++){
            if(c[i]==c[i-1]){
                ans=ans+c[i];
            }
        }
        for(int i=1;i<dl;i++){
            if(d[i]==d[i-1]){
                ans=ans+d[i];
            }
        }

        return ans;
    }
    int ans1=0,ans2=0;
    b[lun]=1;
    ans1=baoli(lun+1);
    b[lun]=0;
    ans2=baoli(lun+1);
    return max(ans1,ans2);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int i1=1;i1<=T;i1++){
        cin>>n;
        for(int i4=0;i4<n;i4++){
            cin>>a[i4];
        }
        cout<<baoli(0)<<endl;

    }

    return 0;
}
