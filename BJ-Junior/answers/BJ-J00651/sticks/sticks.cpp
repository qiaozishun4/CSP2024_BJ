#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    int s[8]={};
    cin>>T;
    s[1]=-1;
    s[2]=1;
    s[3]=7;
    s[4]=4;
    s[5]=2;
    s[6]=0;
    s[7]=8;
    while (T--){
        int n;
        cin>>n;
        if (n<=7){
            if (n==6){
                cout<<6<<endl;
                continue;
            }
            else
                cout<<s[n]<<endl;
        }
        else{
            int x1=n/6,x2=n/7;
            n%6==0? x1 : x1++;
            n%7==0? x2 : x2++;
            if (x1==x2){
                if (n%6==0){
                    x1-=2;
                    cout<<2;
                    for (int i=1;i<=x1;i++)
                        cout<<0;
                    cout<<8<<endl;
                    continue;
                }
                else{
                    if (n%6!=1){
                        if (n%6==3){
                            cout<<2;
                            for (int i=1;i<x1-1;i++)
                                cout<<0;
                            cout<<4<<endl;
                            continue;
                        }
                        else{
                            cout<<s[n%6];
                            for (int i=1;i<x1;i++)
                                cout<<0;
                            cout<<endl;
                            continue;
                        }
                    }
                    else{
                        cout<<8;
                        for (int i=1;i<x1-1;i++)
                            cout<<0;
                        cout<<endl;
                    }
                }
            }
            else{
                if (n%7==0){
                    for (int i=1;i<=x2;i++)
                        cout<<7;
                    cout<<endl;
                    continue;
                }
                else{
                    if (n%7==1){
                        cout<<27;
                        for (int i=1;i<x2-1;i++)
                            cout<<8;
                        cout<<endl;
                        continue;
                    }
                    else if (n%7==3){
                        cout<<40;
                        for (int i=1;i<x2-1;i++)
                            cout<<8;
                        cout<<endl;
                        continue;
                    }
                    else if (n%7==4){
                        cout<<20;
                        for (int i=1;i<x2-1;i++)
                            cout<<8;
                        cout<<endl;
                        continue;
                    }
                    else{
                        cout<<s[n%7];
                        for (int i=1;i<x2;i++)
                            cout<<8;
                        cout<<endl;
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}