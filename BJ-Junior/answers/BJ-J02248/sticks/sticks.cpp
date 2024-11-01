#include<iostream>
using namespace std;
int t;
int n[55],ans[55],f[55];
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i = 0;i < t;i++){
        cin>>n[i];
        if(n[i] % 7 == 0){
            f[i] = 1;
            while(n[i]){
                n[i] -= 7;
                ans[i]++;
            }
        }
        else{
            f[i] = 0;
            n[i] -= 8;
            while(n[i]){
                n[i] -= 7;
                ans[i]++;
            }
        }
    }
    for(int i = 0;i < t;i++){
        if(f[i]){
            for(int j = 0;j < ans[i];j++){
                cout<<8;
            }
            cout<<endl;
        }
        else{
            cout<<1;
            for(int j = 0;j < ans[i];j++){
                cout<<8;
            }
            cout<<6<<endl;
        }
    }
    return 0;
}
