#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int T;
int n;
const int smaaller[]={-1,-1,1,7,4,2,6};
const int biigger[]={8,10,18,22,20,28,68};
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--) {
        cin>>n;
        if(n<7) {
            cout<<smaaller[n]<<endl;
            continue;
        }
        int q=n/7;
        int r=n%7;
        cout<<biigger[r];
        for(int i=0;i<q-1;i++) {
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
