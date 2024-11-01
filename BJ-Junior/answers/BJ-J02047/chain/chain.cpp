#include<iostream>
#include<stdio.h>
using namespace std;
int t;


int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);

    cin>>t;
    for(int i=0;i<t;i++){
        int n,k,q;
        int a[1005][2005];
        int l[1005];
        cin>>n>>k>>q;
        int maxn=-1;
        for(int j=0;j<n;j++){
            cin>>l[j];
            for(int k0=0;k0<l[j];k0++)
                cin>>a[j][k0];
        }

        for(int j=0;j<q;j++){
            int r,c;
            cin>>r>>c;
            if(r==1){
                bool flag=0;
                for(int ki=0;ki<n;ki++){
                    for(int h=0;h<l[ki];h++){
                        while(a[ki][h]!=1&&h<l[ki])
                            h++;
                        for(int g=h;g<h+k&&g<l[ki];g++){
                            if(a[ki][g]==c){
                                flag=1;
                                break;
                            }
                        }
                        if(flag)
                            break;
                    }
                    if(flag)
                        break;
                }
                if(flag)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}