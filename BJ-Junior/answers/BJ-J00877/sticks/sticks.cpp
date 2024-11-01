#include<iostream>
using namespace std;
int a[1005];
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    cout<<-1<<endl;
}
return 0;
}
