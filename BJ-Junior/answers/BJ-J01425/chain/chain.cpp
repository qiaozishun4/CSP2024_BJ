#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.in","r",stdin);
    int T;
    cin >> T;
    for(int lp=0;lp<T;lp++){
        int n,k,q,l;
        vector<short> d[10007];
        for(int i=0;i<n;i++){
            short w;
            cin >> l;
            for(int j=0;j<l;j++){
                cin >> w;
                d[i].push_back(w);
            }
        }
        while(q--){
            int u,v;
            for(int i=u-1;i<v;i++){
                bool f=true;
                if(i==0){
                    f=false;
                    for(int j=0;j<d[i].size()-1;j++){
                        d[i].e
                        if(d[i][j] == 1) f=true;
                    }
                }
                if(!f){
                    cout << 0;
                    continue;
                }
                if(i==v-1){
                    cout << 1;
                    continue;
                }
                bool ff=0;
                for(int j=0;j<d[i].size()){
                    if(d[i][j]==d[i+1][0]){
                        ff=1;
                        break;
                    }
                }
                if(ff) cout << 1;
                else cout << 0;
            }
        }

    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
