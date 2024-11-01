#include <iostream>
#include <cstdio>
using namespace std;
int T,n,l[1000005],l2[1000005][1000005];
int a[1000005]={};

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    for(int j=1;j<=T;j++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            l2[l[i]][l2[l[i]][0]+1]=i;
            l2[l[i]][0]++;
        }
        for(int i=2;i<=n;i++){
            a[i]=a[i-1];
            if(l2[l[i]][0]!=1&&l2[l[i]][0]!=0){
                if(l2[l[i]][1]==i){
                    continue;
                }
                for(int o=2;o<=l2[l[i]][0];o++){
                    if(l2[l[i]][o]>i){
                        break;
                    }
                    if(l2[l[i]][o]==i){
                        a[i]=max(a[i-1],a[l2[l[i]][o-1]]+l[i]);
                        break;
                    }

                }
            }
        }
        cout<<a[n]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
