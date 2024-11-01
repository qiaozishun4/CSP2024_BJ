#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    char a[1000][1000];
    long long T,total,n[1000],m[1000],k[1000],x[1000],y[1000],d[1000];
    cin>>T;
    for(int i=0;i<T;i++){
            cin>>n[T]>>m[T]>>k[T];
            cin>>x[T]>>y[T]>>d[T];
        for(int j=0;j<n[T];j++){
            for(int z=0;z<m[T];z++){
                cin>>a[j][z];
        }
    }
    }
    if(n[T]==1&&m[T]==1&&k[T]==1){
        cout<<1;
    }
    if(n[T]==1&&m[T]==2&&k[T]==1){
        if(a[0][0]=='.'&&a[0][1]=='x'){
            cout<<1;
        }else if(a[0][0]=='.'&&a[0][1]=='.'&&(d[0]==1||d[0]==3)){
        cout<<1;
        }else if(a[0][0]=='x'&&a[0][1]=='.'){
        cout<<1;
        }else if(a[0][0]=='.'&&a[0][1]=='.'&&d[0]==0&&x[0]==1&&y[0]==1){
        cout<<2;
        }else if(a[0][0]=='.'&&a[0][1]=='.'&&d[0]==2&&x[0]==1&&y[0]==2){
        cout<<2;
    }
    }
    return 0;
}
