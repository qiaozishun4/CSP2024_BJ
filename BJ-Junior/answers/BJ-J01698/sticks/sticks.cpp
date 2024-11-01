#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    int a[100005];
    
    while(T--){
		memset(a,0,sizeof(a));
		int t=0;
        int n;
        cin>>n;
        if(n<=1){
            cout<<-1<<endl;
            continue;
        }
        while(n>=7){
            a[++t]=8;
            n-=7;
        }
        if(n%7==1){
            a[t]=0;
            a[++t]=1;
        }
        else if(n%7==2){
            a[++t]=1;
        }
        else if(n%7==3){
            if(t>=1){
                a[t]=0;a[t-1]=0;
                a[++t]=2;
            }
            else{
                a[++t]=7;
            }

        }
        else if(n%7==4){
            if(t>=1){
                a[t]=0;
                a[++t]=2;
            }
            else{
                a[++t]=4;
            }

        }
        else if(n%7==5){
            a[++t]=2;
        }
        else if(n%7==6){
            a[++t]=6;
        }
        for(int i=t;i>=1;i--){
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
