#include<bits/stdc++.h>
using namespace std;
int n,r[200000];
int main()
{
    ifstream fin("duel.in",ios::in);
    ofstream fout("duel.out",ios::out);
    fin>>n;
    for(int i=0;i<n;i++)fin>>r[i];
    sort(r,r+n,greater<int>);
    for(int i=0;i<n;i++)
    {
        int j=i;
        while(r[i]==r[j]||r[j]==-100000000){j++;}
        r[j]=-100000000;
    }
    for(int i=0;i<n;i++)if(r[i]!=-100000000)ans++;
    fout<<ans;
    fin.close();
    fout.close();
    return 0;
}
