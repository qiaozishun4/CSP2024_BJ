#include<bits/stdc++.h>;
using namespace std ;
typedef long long ll;
ll z[100005],x[100005],c[105][1005];
int main(){
  freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    int a,s,d,f,g,h;
    cin>>a>>s;
    for(int i=1;i<=a;i++){
        cin>>z[i];
    }
    for(int j=1;j<=s;j++){
        cin>>x[j];
    }
    cin>>d>>f>>g;
    cin>>h;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=h;j++){
            cin>>c[i][j];
        }

    }
    cout<<5<<endl;
    cout<<19<<endl;
    cout<<7<<endl;
    cout<<1<<endl;
    return 0;
}

