#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(time(0));
    for(int i=1;i<=8;i++){
        cout<<rand()%51+1<<endl;
    }
    return 0;
}
