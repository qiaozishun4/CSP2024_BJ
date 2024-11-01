#include<iostream>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int weishu=n/7;
        if(n%7==1){
            if(n==1){
                cout<<1<<endl;
                continue;
            }
            if(n==8){
                cout<<8<<endl;
                continue;
            }
            int wz=100,cnt=0;
            for(int i=0;i<weishu;i++){
                cnt+=wz*8;
                wz*=10;
            }
        }
        if(n%7==3){
            if(n==3){
                cout<<3<<endl;
                continue;
            }
            if(n==23){
                cout<<2008<<endl;
                continue;
            }
            int wz=1,cnt=0;
            for(int i=0;i<weishu;i++){
                cnt+=wz*8;
                wz*=10;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
