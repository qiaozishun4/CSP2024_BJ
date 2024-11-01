#include<iostream>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int num=0;
    cin>>num;
    for (int i=0;i<=num;i++){
        int n=0;
        cin>>n;
        int m=0;
        m=n/7;
        for(int j=0;j<m;j++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
