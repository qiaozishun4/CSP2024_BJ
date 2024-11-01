#include <bits/stdc++.h>
using namespace std;
int q;
int n;
int mapp[10]={6,2,5,5,4,5,6,3,7,9};
int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>n;
        int sh=n/7;
        int sheng=0;
        if(n%7&&sh!=0){
            sh--;
            sheng=7+n%7;
        }else if(n%7){
            sheng=n%7;
            bool flag=true;
            for(int j=1;j<=9;j++){
                if(mapp[j]==sheng){
                    flag=false;
                    cout<<j<<endl;
                    break;
                }
            }
            if(flag) cout<<-1<<endl;
            continue;
        }else{
            for(int j=1;j<=sh;j++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        int ansa=-1,ansb=-1;
        //cout<<sheng<<endl;
        bool flag2=false;
        for(int j=1;j<=9;j++){
            int tmp=sheng-mapp[j];
            for(int k=0;k<=9;k++){
                if(tmp==mapp[k]){
                    ansa=j;
                    ansb=k;
                    flag2=true;
                    break;
                }
            }
            if(flag2) break;
        }
        if(ansa==-1&&ansb==-1){
            cout<<-1<<endl;
            continue;
        }
        cout<<ansa<<ansb;
        for(int j=1;j<=sh;j++){
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}
