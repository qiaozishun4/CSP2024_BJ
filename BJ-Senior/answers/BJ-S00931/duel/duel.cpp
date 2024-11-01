#include<bits/stdc++.h>
#include<fstream>

using namespace std;

//check your file cin!!!!!open it when you send your program!!!!!!
//ifstream ofstream!!!!!!!

ifstream fin("duel.in");
ofstream fout("duel.out");
const int N = 1e5 + 10;
int n,a[N],ans,cnt,cur;

int main(){
    fin >> n;
    for(int i = 1;i <= n;i ++){
        fin >> a[i];
    }
    sort(a + 1,a + n + 1);
    cur = 1;
    for(int i = 2;i <= n;i ++){
        if(a[i] != a[i - 1]){
            cnt = cnt + cur;
            cur = 0;
        }
        if(cnt > 0){
            ans ++;
            cnt --;
        }
        cur ++;
    }
    fout << (n - ans) << endl;
    return 0;
}
