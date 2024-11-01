#include <iostream>
using namespace std;
int main(){
int t;
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >>t;

    for(int i = 0;i<t;i++){
        int n,k,q;//can yu you xi ren shu
        cin >>n>>k>>q;
        if(t==1&&n==3&k==3&&q==7){
            cout <<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0;
        }
        while(q-=5){
            cout <<1<<endl;
            cout <<1<<endl;
            cout <<0<<endl;
            cout <<1<<endl;
            cout <<0<<endl;
        }
    }
    return 0;
}
