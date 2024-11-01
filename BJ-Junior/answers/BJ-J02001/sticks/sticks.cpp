#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        int laji=n/7;
        if(n%7==0){
            for(int i=0;i<laji;i++){
                cout<<8;
            }
            cout<<endl;
        }else{
            int lajierhao=n/7;
            for(int i=1;i<lajierhao;i++){
                cout<<8;
            }
            cout<<01<<endl;
        }
    }
    return 0;

}
