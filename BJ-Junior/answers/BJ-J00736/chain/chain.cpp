#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,ans[400000],r,c,ks=1,js;
bool f;
struct player{
    int s,pai[100100];
}p[200100];
int main(){
    memset(ans,0,sizeof(ans));
    cin>>t;
    for(int zz=1;zz<=t;zz++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>p[i].s;
            for(int j=1;j<=p[i].s;j++){
                cin>>p[i].pai[j];
            }
        }
        for(int i=1;i<=q;i++){
            cin>>r>>c;
            if(i!=1) ks=js;
            js=c,f=0;
            for(int j=1;j<=n;j++){
                for(int l=1;l<=p[j].s;l++){
                    if(p[j].pai[l]==c) f=1;
                    else goto FGHIJ;
                }
            }
            for(int j=1;j<=n;i++){
                for(int l=1;l<=p[j].s;l++){
                    if(p[j].pai[l]==ks){
                        for(int m=1;m<=k;m++){
                            for(int o=1;o<=p[j+1].s;o++){
                                if(p[j].pai[l]==ks){
                                    if(p[j+1].pai[o]==p[j].pai[l+m]&&j!=n){
                                        goto ABCDE;
                                    }else if(j==n&&p[j].pai[l+m]==js) f=1;
                                    else goto FGHIJ;
                                }
                            }
                        }
                    }
                }
                ABCDE:
            }
            FGHIJ:
            ans[i]=f;
        }
        for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
    }
	return 0;
}
