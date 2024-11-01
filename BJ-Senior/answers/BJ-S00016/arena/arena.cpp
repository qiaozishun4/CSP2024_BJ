#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(time(0));
    cin>>t;
    while(t--){
        cout<<rand()%10000000+1<<endl;
    }

    return 0;
}
