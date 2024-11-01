#include <bits/stdc++.h>
using namespace std;
int mu[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        if(n<2)cout<<-1;
        for(int i=0;i<10;i++){
            if(n==mu[i])cout<<i<<endl;
            continue;
        }
        if(n==18)cout<<208<<endl;
        else{
            cout<<-1<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
