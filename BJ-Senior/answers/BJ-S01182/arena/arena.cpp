#include<iostream>
using namespace std;
int main(){
freopen("arena.in","r",stdin);
freopen("arena.out","w",stdout);

        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>n;
        }
        for(int i=0;i<m;i++){
            cin>>m;
        }
        int t,a,b,c,d;
        for(int i=0;i<t;i++){
            cin>>a>>b>>c>>d;
        }
        for(int i=0;i<n;i++){
            cout<<a*2+b-c+d;
        }


    return 0;
}
