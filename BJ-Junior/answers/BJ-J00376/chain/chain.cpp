#include<bits/stdc++.h>
using namespace std;
int ciku[10005][105];
int y[10005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;cin>>t;
    for(int ee=1;ee<=t;ee++){
        int n,k,q;cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>y[i];
            for(int j=1;j<=y[i];j++){
                ciku[i][j];
            }
        }
        int flag=0;
        for(int ei=1;ei<=q;ei++){
                int aa,bb;cin>>aa>>bb;
                int ff;
                flag=0;
            for(int i=1;i<=n&&flag==0;i++){//start
                    ff=i;
                for(int j=1;j<=aa&&flag==0;j++){//number
                    for(int u=1;u<=aa&&flag==0;u++){//give
                        if(u!=ff)ff=u;
                        if(u==aa&&ff==bb)flag=1;
                    }
                }
            }
            cout<<flag<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
return 0;}
