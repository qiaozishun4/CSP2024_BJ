#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int T;
    cin>>T;
    srand(time(NULL));
    for(int i=0;i<T;i++){
        cout<<rand()%100000<<endl;
    }
    return 0;
}