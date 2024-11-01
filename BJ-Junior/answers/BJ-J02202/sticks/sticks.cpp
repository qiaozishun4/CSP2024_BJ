#include<bits/stdc++.h>
using namespace std;
int a[10]={0,1,2,4,6,7,8},b[10]={6,2,5,4,6,3,7};
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    
    int t;
    cin>>t;
    while(t--){
        int n,k=0;
        bool fl=false;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }  
        while(n>7){
            a[0]=0;
            int i=0;
            if(!fl)i++;
            bool f=false;
            for( ;i<7;i++){
                if(n-b[i]<=k*7){
                    fl=true;
                    cout<<a[i];
                    n-=b[i];
                    k--;
                    f=true;
                    break;
                }
            }
            if(!f)k++;
            //cout<<k<<endl;
        }
        for(int i=0;i<7;i++){
            if(n==b[i]){
                if(n==6&&!fl){
                    cout<<6<<endl;
                    break;
                }
                cout<<a[i]<<endl;
                break;
            }
        }
    }
    return 0;
}