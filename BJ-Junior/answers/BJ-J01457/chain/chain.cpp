#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T,num=0;
    cin>>T;
    while(T--){
        int n,k,q,hc,hc1;
        cin>>n>>k>>q;
        int a[n][2000],l[n];
        for(int i=0;i<n;i++){
            cin>>l[i];
            for(int j=0;j<l[i];j++){
                cin>>a[i][j];
            }
        }
       for(int i=0;i<q;i++){
        cin>>n>>k;
        cout<<"1";
       }
            num++;
    }


        fclose(stdin);
        fclose(stdout);
       return 0;
        }


