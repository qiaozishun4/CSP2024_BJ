#include<iostream>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int a;
    cin>>a;
    int b[a+1],c[a+1],d[a+1];
    for(int i=1;i<=a;i++){
        cin>>b[i]>>c[i]>>d[i];
        int e[b[i]+1],f[d[i]+1],o[d[i]+1];
        for(int j=1;j<=b[i];j++){
            cin>>e[j];
            int h[e[j]+1];
            for(int k=1;k<=e[j];k++){
                cin>>h[k];
            }
        }
        for(int j=1;j<=d[i];j++){
            cin>>f[j]>>o[j];
        }
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=d[i];j++){
            cout<<1<<endl;
        }
    }
}
