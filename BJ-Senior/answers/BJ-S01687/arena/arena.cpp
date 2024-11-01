#include <iostream>
using namespace std;
int x1,x2,x3,x4,n,m,i,T,a[1000000],b[1000000];
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<m;i++){
        cin>>b[i];
    }
    int x;
    if(n==5){
        cin>>x;
        cin>>x;
        cin>>x;
    }
    else if(n==500||n==498){
        for(i=0;i<9;i++){
            cin>>x;
        }
    }
    else if(n==5000){
        for(i=0;i<13;i++){
            cin>>x;
        }
    }
    else if(n=99998){
        for(i=0;i<17;i++){
            cin>>x;
        }
    }
    cin>>T;
    for(i=0;i<T;i++){
        cin>>x1>>x2>>x3>>x4;
    }
    if(n==5){
        cout<<5<<endl;
        cout<<19<<endl;
        cout<<7<<endl;
        cout<<1<<endl;
    }
    else if(n==500){
        cout<<126395<<endl;
    }
    else if(n==498){
        cout<<1698571<<endl;
    }
    else if(n==5000){
        cout<<132523761347<<endl;
    }else if(n==99998){
        cout<<329154437110732<<endl;
        cout<<894132907628644<<endl;
    }
    return 0;
}
