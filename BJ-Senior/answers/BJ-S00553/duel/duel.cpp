#include<bits/stdc++.h>
using namespace std;
struct s{
	int v;
	bool flag;
	bool l;
}r[100010];
bool cmp(s x, s y){
    return x.v < y.v;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
	int n;
	cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> r[i].v;
        r[i].flag = true;
        r[i].l = true;
    }
    sort(r + 1,r + n + 1,cmp);
    for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			if(r[i].v<r[j].v && r[j].flag && r[i].l && r[j].l){
                r[i].l = false;
                r[j].flag = false;
                continue;
			}
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++){
        if(r[i].l) cnt++;
	}
	cout << cnt << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
