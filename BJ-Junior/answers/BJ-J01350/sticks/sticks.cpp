#include<bits/stdc++.h>
using namespace std;
int h[30]={-1,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int v[10]={7,6,5,4,3,2},d[10]={8,0,2,4,7,1};
stack<int> st;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n<=20) cout<<h[n];
        else if(n%7==0){
            for(int i=1;i<=n/7;i++) printf("8");
        }
        else if(n%7==1){
            cout<<10;
            for(int i=1;i<=(n-8)/7;i++) printf("8");
        }
        else{
            int cur=0;
            while(n){
                while(n>=v[cur]){
                    if(n-v[cur]==0&&cur==1) cout<<6;
                    else{
                        st.push(d[cur]);
                        n-=v[cur];
                    }
                    if(n<=20){
                        cout<<h[n];
                        n=0;
                        break;
                    }
                }
                cur++;
            }
            while(!st.empty()){
                printf("%d",st.top());
                st.pop();
            }
        }
        cout<<"\n";
    }
    return 0;
}
