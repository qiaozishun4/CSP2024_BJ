#include<bits/stdc++.h>
using namespace std;

map<int,int>m;

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;cin>>T;
    int n,tmp;
    while(T--){
        m.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>tmp;
            m[tmp]++;
        }
        int sum=0;
        for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
            if(it->second>1)sum+=(it->second-1)*it->first;
        }
        cout<<sum<<endl;
    }
    return 0;
}
