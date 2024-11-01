#include<iostream>
using namespace std;
int n,num[9]={6,2,5,5,4,5,6,3,7};
long long f[100001];
int main() {
    freopen("sticks1.in","r",stdin);
    freopen("sticks.out","w",stdout);
    f[1]=-1;
    f[2]=1;
    f[3]=7;
    f[4]=4;
    f[5]=2;
    f[6]=6;
    f[7]=8;
    f[8]=16;
    int T;
    cin>>T;
    for(int t=0;t<T;t++) {
        cin>>n;
        cout<<f[n%7];
        for(int i=0;i<n/7;i++) cout<<8;
        cout<<endl;
    }
    return 0;
}
