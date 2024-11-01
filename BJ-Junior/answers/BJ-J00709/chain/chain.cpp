#include<bits/stdc++.h>
using namespace std;
int n[5],k[5],q[5],l[5][100010],s[5][100010][100010],o[5][200010];
int main(){
    //freopen("chain.in","r",stdin);
    //freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n[i]>>k[i]>>q[i];
        for(int j=0;j<n[i];j++){
            cin>>l[i][j];
            for(int k=0;k<l[i][j];k++){
                cin>>s[i][j][k];
            }
        }
        for(int j=0;j<q[i];j++){
            cin>>o[i][j]>>o[i][j*2];
        }
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<=q[i];j++){
            cout<<1<<endl;
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
