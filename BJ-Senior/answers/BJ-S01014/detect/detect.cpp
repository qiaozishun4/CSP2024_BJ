#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int T;
bool f[10000];

int car(int d, int v, int a, int L, int V){
    int s=L-d;

    if(v>V) return 1;
    if(sqrt(v*v+2*a*s)>V) return 1;

    return 0;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);

    cin>>T;

    while(T--){
        int n,m,L,V;
        int numc=0,nume=0;
        cin>>n>>m>>L>>V;

        for(int i=0;i<n;i++){
            int d,v,a;
            cin>>d>>v>>a;
            if(car(d,v,a,L,V)){
                numc++;
                f[i]++;
            }
        }

        for(int j=0;j<m;j++)
            if(f[m]==0) nume++;

        cout<<numc<<" "<<nume<<endl;
    }

    return 0;
}
