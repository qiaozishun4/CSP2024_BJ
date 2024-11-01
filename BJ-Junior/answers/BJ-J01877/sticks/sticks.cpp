#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
stack<int> st;
int oldk;
int stick[10]={6,2,5,5,4,5,6,3,7,6};
int dfs(int n,int k){
    if(k>0){
    if(n<2*k || n>7*k){
        st.pop();
        return 0;
    }else{
        for(int i=0;i<10;i++){
            if(n>=stick[i]  ){
                if(k==oldk && i==0){
                    continue;
                }else{
                    st.push(i);
                    if(dfs(n-stick[i],k-1)){
                        return 1;
                    }else{
                        continue;
                    }

                }

            }
        }
        return 0;
    }
    }else{

        if(n>0){
            st.pop();
            return 0;
        }else{
            return 1;
        }
    }
}
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    int n;
    int t;
    cin>>t;
    while(t--){


    cin>>n;
    if(n%7==0){
        for(int i=0;i<n/7;i++){
            cout<<8;
        }
        cout<<endl;
        continue;
    }else if(n%7==1){
        if(n==1){
            cout<<1<<endl;
        }else if(n==8){
            cout<<16<<endl;
        }else{
            cout<<16;
            for(int i=2;i<n/7+1;i++){
                cout<<8;
            }
            cout<<endl;
        }
        continue;
    }

    if(n==1){
        cout<<-1<<endl;
    }else{
        oldk=(n%7==0)? n/7 : n/7+1;
        dfs(n,(n%7==0)? n/7 : n/7+1);

        int a[10005];
        int s=st.size();
        for(int i=0;i<s;i++){
            a[i]=st.top();
            st.pop();
        }
        for(int i=s-1;i>=0;i--){
            cout<<a[i];
        }
        cout<<endl;
    }
    }
    return 0;
}
