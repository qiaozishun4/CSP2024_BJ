#include <bits/stdc++.h>
using namespace std;
int t,n;
string a[100005];
map<string,int> m;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    a[1]="-1";
    a[2]="1";
    a[3]="7";
    a[4]="4";
    a[5]="2";
    a[6]="6";
    a[7]="8";
    a[8]="10";
    a[9]="18";
    a[10]="22";
    a[11]="20";
    a[12]="28";
    a[13]="68";
    a[14]="88";
    for(int k=2;k<=14281;k++){
        m.clear();
        for(int j=7*(k-1)+1;j<=7*k;j++){
            m.insert(make_pair(a[j],j));
        }
        for(int i=7*k+1;i<=7*(k+1);i++){
            m.erase(a[i-8]);
            int temp=i-m.begin()->second;
            string x;
            if(temp==6)
                x="0";
            else
                x=a[temp];
            a[i]=m.begin()->first+x;
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        cout<<a[n]<<endl;
    }

    return 0;
}
