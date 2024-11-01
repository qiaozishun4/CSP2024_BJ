#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,ans;
double d[100005],v[100005],a[100005],ce[100005],V;
int main (){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>T;

    for(int i=1;i<=T;i++){

        cin>>n>>m>>L>>V;
        double ce_max=0;
        for(int j=1;j<=n;j++){

            cin>>d[j]>>v[j]>>a[j];
        }
        for(int j=1;j<=m;j++){
            cin>>ce[j];
            ce_max=max(ce[j],ce_max);
        }
        int ans=0;
        for(int j=1;j<=n;j++){
            if(v[j]>V&&d[j]<=ce_max){
                ans++;
            }
        }
        if(ans==0){

            cout<<ans<<" "<<m<<endl;
        }
        else{
            cout<<ans<<" "<<m-1<<endl;
        }

    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}