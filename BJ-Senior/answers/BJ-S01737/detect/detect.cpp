#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int total;
    cin >> total;
    for(int j = 0;j < total;j++){
        int n,m,l,va;
        cin >> n>>m>>l>>va;
        int d[100010];
        int v[100010];
        int cnt = 0;
        for(int i = 0;i <n;i++){
            int b,c;
            cin>>d[i]>>v[i]>>c;
        }
        for(int i = 0;i < m-1;i++){
            int a;
            cin >>a;
        }
        int s;
        cin >>s;
        for(int i = 0;i <n;i++){
            if(v[i] > va&&d[i] <= s)
                cnt++;
        }
        cout << cnt <<" "<< m-1<<endl;
    }
    return 0;
}