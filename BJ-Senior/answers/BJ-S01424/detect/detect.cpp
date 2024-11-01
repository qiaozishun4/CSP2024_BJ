#include<bits/stdc++.h>
using namespace std;
double vc[10000];
double a[10000];
double x[10000];
double mw[10000];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    double n,m,l,v;
    double j=0;
    double gb=0;
    double jl;
    int ljq=0;
    for(int i=0;i<T;i++){
        cin>>n>>m>>l>>v;
        for(int j=0;j<n;j++){
            cin>>x[j]>>vc[j]>>a[j];

        }
        for(int q=0;q<m;q++){
            cin>>mw[q];
        }
        for(int w=0;w<n;w++){
            if(x[w]>l){
                break;
            }
            if(a[w]==0){
                if(vc[w]>v){
                    j++;
                    gb++;
                }
            }
            jl=(v*v-vc[w]*vc[w])/(2*a[w]);
            if(a[w]>0){
                if(jl<0){
                    j++;
                    gb++;
                    }else if(jl>0){
                        if(jl+x[w]<l){
                            j++;
                            gb++;
                        }
                }if(a[w]<0){
                    if(jl>0){
                        while(1){
                            if(x[w]<=mw[ljq]<=x[w]+jl){
                                j++;
                                gb++;
                                break;
                            }
                            ljq++;
                        }
                    }
                }
            }
        }
        cout<<j<<" "<<m-gb<<endl;
    }


return 0;
}
