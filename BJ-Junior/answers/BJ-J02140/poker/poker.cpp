#include<bits/stdc++.h>
using namespace std;
struct A{
    char a,b;
};
bool cmp(A x,A y){
    if(x.a==y.a){
        return x.b<y.b;
    }
    return x.a<y.a;
}
int main(){
    freopen("poker.in","r",stdin);

   freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    A a[52];
    int s=1;
    for(int i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b;
}
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n;i++){
	if(a[i].a!=a[i-1].a||a[i].b!=a[i-1].b){
            s++;
        }
    }
    cout<<52-s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
