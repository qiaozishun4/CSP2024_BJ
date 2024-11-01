#include<bits/stdc++.h>
using namespace std;
int a[100005];
stack<int> st;
int main(){
    int x=0;
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    a[0]=-1;
    a[1]=-1;
    a[2]=1;
    a[3]=7;
    a[4]=4;
    a[5]=2;
    a[6]=6;
    a[7]=8;
    a[8]=16;
    for(int i=9;i<=100003;i++){
        a[i]=min(a[i-2],min(a[i-3],min(a[i-4],min(a[i-5],min(a[i-6],a[i-7])))));
        for(int j=2;j<=7;j++){
            if(a[i]==a[i-j]){
                a[i]*=10;
                a[i]+=a[j];
            }
        }
    }
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        while(a[n]>=10){
            if(a[n]%10==6){
                st.push(0);
            }else{
                st.push(a[n]%10);
            }
            a[n]/=10;
        }
        while(st.size()>0){
            a[n]=a[n]*10+st.top();
            st.pop();
        }
        cout << a[n] << endl;
    }
    return 0;
}

