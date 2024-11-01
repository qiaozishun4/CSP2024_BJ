#include <bits/stdc++.h>
using namespace std;
int t,n,k,q,l[100010],r[100010],c[100010];
string s[100010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> k >> q;
        char inpu;
        int ha[10]={0};
        int cnt=0;
        for(int i=0;i<n;i++){
            s[i]="";
            cin >> l[i];
            bool can=1;
            for(int j=0;j<l[i];j++){
                cin >> inpu;
                ha[inpu-'0']++;
                if(ha[inpu-'0']==2){
                    if(can)
                        cnt++;
                    else ha[inpu-'0']=1;
                }
                s[i]+=inpu;
            }
        }
        for(int i=0;i<q;i++){
            cin >> r[i] >> c[i];
            cout << (!!ha[c[i]]) << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
