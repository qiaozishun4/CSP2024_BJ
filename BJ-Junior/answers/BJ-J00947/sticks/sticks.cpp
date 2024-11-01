#include<bits/stdc++.h>
using namespace std;
int T;
int st[8]={0,0,1,7,4,2,6,8};
signed main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        int pos=1;
        while(n>0){
            if(pos>1){
                st[6]=0;
            }
            if(n%7==0){
                for(int i=1;i<=(n/7);i++){
                    cout<<8;
                }
                break;
            }
            else{
                int tmp=n%7;
                int num=INT_MAX;
                int id=0;
                if(n==8){
                    if(pos==1){
                        cout<<"10"<<endl;
                    }
                    else{
                        cout<<"01"<<endl;
                    }
                    break;
                }
                for(int i=max(2,tmp);i<=min(n,7);i++){
                    if(st[i]<num){
                        id=i;
                        num=st[i];
                    }
                }
                cout<<num;
                n-=id;
                pos++;
            }
        }
        cout<<endl;
        st[6]=6;
    }
    return 0;
}
