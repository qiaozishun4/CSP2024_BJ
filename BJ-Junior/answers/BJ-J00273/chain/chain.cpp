
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;


int main(){

    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n,k,q;
        cin>>n>>k>>q;
        vector<string>s;
        for(int j=0;j<n;j++){
            cin>>s[i];
        }
        for(int j=0;j<q;j++){
            int ci,ji;
            cin>>ci>>ji;

            if(ci%2==1){
                int sum=0;
                for(int l=0;l<n;l++){
                    if(s[i].find('ji')!=-1){
                        sum++;
                    }
                }
                if(sum%2==0){
                    cout<<1<<endl;
                }
                else{
                    cout<<0<<endl;
                }
            }
            if(ci%2==0){
                cout<<1<<endl;

            }
        }

    }


    fclose(stdin);
    fclose(stdout);
    return 0;
    }
