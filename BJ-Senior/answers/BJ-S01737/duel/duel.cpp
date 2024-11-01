#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    int m=100000;
    int x = 0;
    int p[100010];
    int num[100010];
    cin >>n;
    for(int i = 0;i <= 100010;i++){
        p[i] = 0;
    }
    for(int i = 1;i<=n;i++){
        long long a;
        cin >>a;
        p[a]++;
        if(a < m) m=a;
        if(a > x) x=a;
    }
    //cout <<n<<m<<x<<endl;
    int j = 1;
    for(int i = x+1;i >= m-1;i--){
        if(p[i] != 0){
            num[j] = i;
            j++;
        }
    }
    int cnt = 0;
    int c = 0;
    for(int i = 1;i<= j;i++){
        //cout << num[i]<<" "<<p[num[i]]<<endl;
        if(cnt < p[num[i]]){
            c = c+p[num[i]]-cnt;
            //cout << num[i]<< " "<<p[num[i]]-cnt<<endl;
            cnt = p[num[i]];
        }
    }
    cout << c;
}