#include <bits/stdc++.h>
using namespace std;
string p[200];
int f[15]={99,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,c,r=0,d=1;
    bool u=false;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(p[j]==p[i]){
                for(int k=1;k<=d;k++){
                    if(f[k]==j or f[k]==i){
                        u=true;
                        break;
                    }
                }
                if(u==false){
                    r++;
                    f[d]=j;
                    d++;
                }
                else{
                    u=false;
                }
            }
        }
    }
    c=52-n+r;
    cout<<c<<endl;
    return 0;
}
