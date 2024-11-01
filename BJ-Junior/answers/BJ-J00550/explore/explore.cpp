#include <iosteam>
using namespace std
int s,n,m,k,x,y,d;
int main(){
    freopen("explore.in",'r',stdin);
    freopen("explore.out",'w',stdout);
    for(int i=1;i<=s;i++){
        cin>>n>>m>>k;
        cin>>x>>y>>d;
        if(d==0){
            if(y+1>m){
                cout<<1;
            }
            else{
                cout<<2;
            }
        }
        else if(d==1){
            if(x+1>n){
                cout<<1;
            }
            else{
                cout<<2;
            }
        }
        else if(d==2){
            if(y-1<1){
                cout<<1;
            }
            else{
                cout<<2;
            }
        }
        else if(d==3){
            if(x-1<1){
                cout<<1;
            }
            else{
                cout<<2;
            }
        }
    }
    return 0;
}
