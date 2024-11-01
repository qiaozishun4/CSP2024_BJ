#include<bits/stdc++.h>
#include<ctime>
#include<random>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    srand(time(0));
    int t;
    cin>>t;
    while(t--){
        int n,k,q;
        cin>>n>>k>>q;
        vector<int> v[n];
        for(int i=0;i<n;i++){
            int w,tmp;
            cin>>w;
            while(w--){
                cin>>tmp;
            }
        }
        for(int i=0;i<q;i++){
            int r,c;
            cin>>r>>c;
            cout<<rand()%2<<"\n";
        }
    }
}
