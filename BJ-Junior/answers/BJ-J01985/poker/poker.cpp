#include<bits/stdc++.h>
using namespace std;
struct poker{
    char a;
    char b;
};
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int m=n;
    poker p[60];
    for(int i=0;i<n;i++){
        cin>>p[i].a>>p[i].b;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(p[i].a==p[j].a && p[i].b==p[j].b){
                m--;
                break;
            }
        }
    }
    cout<<52-m;
    return 0;
}
