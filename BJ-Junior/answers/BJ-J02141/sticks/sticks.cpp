#include<bits/stdc++.h>
using namespace std;
int t,n,minn;
int dfs(int n,int ws){
    if(n==2){
        return 1*pow(10,ws);
    }else if(n==3){
        return 7*pow(10,ws);
    }else if(n==4){
        return 4*pow(10,ws);
    }else if(n==5){
        return 2*pow(10,ws);
    }else if(n==6){
        return 6*pow(10,ws);
    }else if(n==7){
        return 8*pow(10,ws);
    }else{
        return min(dfs(n-6,ws+1),min(dfs(n-2,ws+1),min(dfs(n-5,ws+1),min(dfs(n-5,ws+1),min(dfs(n-4,ws+1),min(dfs(n-5,ws+1),min(dfs(n-6,ws+1),min(dfs(n-3,ws+1),min(dfs(n-7,ws+1),dfs(n-6,ws+1))))))))));
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            continue;
        }else if(n==2){
            cout<<1<<endl;
            continue;
        }
        if(n%7==0){
            int nn=n/7;
            for(int i=1;i<=nn;i++){
                cout<<8;
            }
            cout<<endl;
            continue;
        }
        if(n==18){
            cout<<208<<endl;
            continue;
        }else if(n==10){
            cout<<22<<endl;
            continue;
        }else if(n==11){
            cout<<20<<endl;
            continue;
        }else if(n==12){
            cout<<28<<endl;
            continue;
        }else if(n==13){
            cout<<68<<endl;
            continue;
        }else if(n==14){
            cout<<88<<endl;
            continue;
        }else if(n==15){
            cout<<108<<endl;
            continue;
        }else if(n==16){
            cout<<188<<endl;
            continue;
        }else if(n==17){
            cout<<228<<endl;
        }else if(n==19){
            cout<<288<<endl;
            continue;
        }else if(n==20){
            cout<<688<<endl;
            continue;
        }
        string sss="";
        int ann=n;
        if(n>20){
            for(int i=n;i>=10;i-=7){
                if(i<=20){
                    break;
                }else{
                    sss+='8';
                }
                ann-=7;
            }
        }
        if(ann==18){
            cout<<208<<sss<<endl;
            continue;
        }else if(ann==10){
            cout<<22<<sss<<endl;
            continue;
        }else if(ann==11){
            cout<<20<<sss<<endl;
            continue;
        }else if(ann==12){
            cout<<28<<sss<<endl;
            continue;
        }else if(ann==13){
            cout<<68<<sss<<endl;
            continue;
        }else if(ann==14){
            cout<<88<<sss<<endl;
            continue;
        }else if(ann==15){
            cout<<108<<sss<<endl;
            continue;
        }else if(ann==16){
            cout<<188<<sss<<endl;
            continue;
        }else if(ann==17){
            cout<<228<<sss<<endl;
        }else if(ann==19){
            cout<<288<<sss<<endl;
            continue;
        }else if(ann==20){
            cout<<688<<sss<<endl;
            continue;
        }
        minn=dfs(n,0);
        cout<<minn<<endl;
    }
    return 0;
}