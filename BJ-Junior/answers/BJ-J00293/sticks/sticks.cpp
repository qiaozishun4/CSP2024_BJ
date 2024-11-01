#include <iostream>
#include <cstring>
using namespace std;

int dc[]={6,2,5,5,4,5,6,3,7,6};
int a666[]={-1,-1,1,7,6,2,6,8};
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n<=7) {
            cout<<a666[n]<<endl;
        }
        else {
            string s="";
            if(n%7==0) s="8";
            if(n%7==1) s="10";
            if(n%7==2) s="18";
            if(n%7==3) s="22";
            if(n%7==4) s="20";
            if(n%7==5) s="28";
            if(n%7==6) s="80";
            cout<<s;
            for(int i=1;i<=n/7-1;i++) cout<<'8';
            cout<<endl;
        }
    }
    return 0;
}
