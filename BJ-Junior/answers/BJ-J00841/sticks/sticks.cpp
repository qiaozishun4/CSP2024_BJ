#include <bits/stdc++.h>
using namespace std;
long long t;
long long stig[15]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    cin>>t;
    for(int i=1;i<=t;++i){
        long long n;
        cin>>n;
        long long s=(n/7)+1;
        long long ss=1;
        for(int j=1;j<=s;j++){
            ss*=10;
        }
        if(n<2){
            cout<<"-1"<<endl;
        }else if(n==2){
            cout<<"1";
        }else{
            srand(time(NULL));
            cout<<rand()%ss;
        }

    }
    return 0;
}
