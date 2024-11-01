#include<bits/stdc++.h>
using namespace std;
int stick_num[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int x;
        bool flag=1;
        cin>>x;
        for(int i=1;i<10;i++){
            if(stick_num[i]==x){
                cout<<i<<endl;
                flag=0;
                break;
            }
        }
        if(flag){
                for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        if(stick_num[i]+stick_num[j]==x){
                            cout<<i<<j<<endl;
                            flag=0;
                            break;
                        }
                    }
                    if(!flag) break;
                }
        }
        if(flag){
            for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            if(stick_num[i]+stick_num[j]+stick_num[k]==x){
                                cout<<i<<j<<k<<endl;
                                flag=0;
                                break;
                            }
                        }
                        if(!flag) break;
                    }
                    if(!flag) break;
                }
                if(!flag) break;
        }
        if(flag){
            for(int i=1;i<10;i++){
                    for(int j=0;j<10;j++){
                        for(int k=0;k<10;k++){
                            for(int w=0;w<10;w++){
                                if(stick_num[i]+stick_num[j]+stick_num[k]+stick_num[w]==x){
                                    cout<<i<<j<<k<<w<<endl;
                                    flag=0;
                                    break;
                                }
                            }
                            if(!flag) break;
                        }
                        if(!flag) break;
                    }
                    if(!flag) break;
                }
                if(!flag) break;
        }
        if(flag){
            cout<<-1<<endl;
        }
    }
    return 0;
}
