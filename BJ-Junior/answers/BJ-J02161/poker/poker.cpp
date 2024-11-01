#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    long long n,a;
    cin>>n;
    char b[2][52],c[2][52];
    for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin>>b[j][i];
            }

    }
    a=52-n;
            for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                c[j][i]=b[j][i];
            }
     }
     if(n==1)cout<<51;
     else if(n>2&&n<53){
     for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                for(int x=0;i<n;i++){
            for(int y=0;j<2;j++){
                if(b[j][i]==c[y][x]){
                    a++;
                }
            }
            }
            }
     }
     cout<<a;
     }

    return 0;
}
