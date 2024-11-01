#include<bits/stdc++.h>
using namespace std;

int ans[100010];

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    int T;
    cin>>T;
    while(T>0){
        int n;
        cin>>n;
        if(n<2){
            cout<<-1<<endl;
            T--;
            continue;
        }
        if(n==6){
            cout<<6<<endl;
            T--;
            continue;
        }
        if(n%7==0){
            for(int i=1;i<=n/7;i++){
                cout<<8;
            }
            cout<<endl;
            T--;
            continue;
        }
        if(n%7==1){
            cout<<10;
            for(int i=1;i<=(n/7)-1;i++){
                cout<<8;
            }
            cout<<endl;
            T--;
            continue;
        }

        int k=0;
        while(n>0){
            if((n%11)==0){
                ans[++k]=2;
                ans[++k]=0;
                n-=11;
            }
            else if(n>=7&&n!=8){
                ans[++k]=8;
                n-=7;
            }
            else if(n>=6){
                ans[++k]=0;
                n-=6;
            }
            else if(n>=5){
                ans[++k]=2;
                n-=5;
            }
            else if(n>=4){
                ans[++k]=4;
                n-=4;
            }
            else if(n>=3){
                ans[++k]=7;
                n-=3;
            }
            else if(n>=2){
                ans[++k]=1;
                n-=2;
            }
        }
        sort(ans+1,ans+1+k);
        if(ans[1]==0){
            int i;
            for(i=1;ans[i]==0;i++);
            swap(ans[1],ans[i]);
        }
        for(int i=1;i<=k;i++){
            printf("%d",ans[i]);
        }
        cout<<endl;
        T--;
    }
    return 0;
}
