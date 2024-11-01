#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,a[100005];
long long cnt;
bool vis[100005];
int main(){
    std::cin.tie(0);std::cout.tie(0);
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> a[i];
        vis[i]=1;
        //check[i]=1;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
                if(vis[j]&&a[j]<a[i]){
                vis[j]=0;
                //check[i]=0;
                cnt--;
                break;
            }
        }
        //if(vis[i])cnt++;
        cnt++;
    }
    /*for(int i=0;i<n;i++){
    	if(vis[i]){
            cnt++;
        }
    }*/
    cout << cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}