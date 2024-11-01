#include<bits/stdc++.h>
using namespace std;
const int Num_Need[10]={6,2,5,5,4,5,6,3,7,6};
vector<int> split(int j){
    string s=to_string(j);
    vector<int>v;
    for(auto a:s){
        v.push_back(a-'0');
    }
    return v;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==0||n==1){
            cout<<-1<<"\n";
            continue;
        }
        bool flg=true;
        for(int i=1;flg;i++){
            vector<int> g=split(i);
            long long need=0;
            for(auto a:g){
                need+=Num_Need[a];
            }
            if(n==need){
                cout<<i<<"\n";
                flg=false;
                break;
            }
        }
        if(flg)
            cout<<-1<<"\n";
    }

}
