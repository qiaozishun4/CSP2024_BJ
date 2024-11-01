#include <bits/stdc++.h>
using namespace std;

int T;
string m[15]={"","","1","7","4","2","6","8","10","18","22","20"};

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=1){
            cout<<"-1\n";
            continue;
        }
        if(n<=11){
            cout<<m[n];
        }
        else if(n-17>=0 and (n-17)%7==0){
            cout<<206;
            for(int i=1;i<=(n-17)/7;i++){
                cout<<8;
            }
        }
        else{
                int c=0;
            while(n>11){
                n-=7;
                c++;
            }
            cout<<m[n];
            for(int i=1;i<=c;i++){
                cout<<8;
            }
        }
        cout<<"\n";
    }
    return 0;
}
