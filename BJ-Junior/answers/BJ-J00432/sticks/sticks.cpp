#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int num=n%7;
        int k=n/7;
        if(!k){
            int box[7]={-1,-1,1,7,4,2,6};
            cout<<box[num]<<'\n';
        }else{
            int box[7]={8,10,18,22,20,28,68};
            cout<<box[num];
            for(int i=0;i<k-1;i++){
                cout<<8;
            }
            cout<<'\n';
        }
    }
    return 0;
}
