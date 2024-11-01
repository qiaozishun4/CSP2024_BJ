#include <iostream>
using namespace std;
int n,r[100005],q[100005],t,s,top=0,endd=0;
void push(int a);
int tope();
int pop();
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    for(int i=0;i<n;++i){
        r[i]=0;
    }
    cin>>n;
    s=n;
    for(int i=0;i<n;++i){
        cin>>t;
        ++r[t];
    }
    for(int i=0;i<100005;++i){
        if(r[i]==0)continue;
        for(int j=0;j<r[i];++j){
                push(i);
        }
        while(tope()<i&&r[i]!=0){
            --s;
            --r[i];
            pop();
        }
    }
    cout<<s<<endl;
    return 0;
}
void push(int a){
    q[endd++]=a;
}
int tope(){
    return q[top];
}
int pop(){
    return q[top++];
}
