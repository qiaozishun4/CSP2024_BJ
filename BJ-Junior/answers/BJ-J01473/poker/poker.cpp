#include<bits/stdc++.h>
using namespace std;
int n;
bool a[100];
string z[5],q[]={"DCHS"};
string w[]={"A23456789TJQK"};
int main(){
    cin>>n;
    while(n--){
        cin>>z;
        a[q.find(z[0])*13+w.find(z[1])]=1;
    }
    for(int i=0;i<52;i++){
        n+=a[i];
    }
    cout<<53-n;
    return 0;
}
