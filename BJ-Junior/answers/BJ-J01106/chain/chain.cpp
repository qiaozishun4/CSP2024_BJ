#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
long long n,w,e,r;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0));
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<rand()%2<<endl;
    }

    return 0;
}
