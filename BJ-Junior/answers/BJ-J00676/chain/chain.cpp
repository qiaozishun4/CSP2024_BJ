#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<fstream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k,q;
vector<int>vec[100005];
bool chain(int b,int x,int y,int l){
    if(x==1){
        for(int i=1;i<=n;i++){
            if(i==l) continue;
            int p=0;
            bool f=0;
            for(auto u:vec[i]){
                if(f) p++;
                if(u==y&&p>=2)return true;
                if(u==b) f=1,p=1;
                if(p==k) f=0,p=0;
            }
        }
        return false;
    }
    for(int i=1;i<=n;i++){
        if(i==l) continue;
        int p=0;
        bool f=0;
        for(auto u:vec[i]){
            if(f) p++;
            if(u==b) f=1,p=1;
            if(p>1){
                bool k=chain(u,x-1,y,i);
                if(k) return true;
            }
            if(p==k) f=0,p=0;
        }
    }
    return false;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            while(a--){
                int p;
                cin>>p;
                vec[i].push_back(p);
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            cout<<chain(1,x,y,0)<<"\n";
        }
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}

