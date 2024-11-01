#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1e5+10;
int a[MAXN],n,ans = LONG_LONG_MAX;
map<int,int> mp,f,cp;
signed main() {
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++)	{
		cin>>a[i];
		mp[a[i]]++,f[a[i]]++;
	}
	sort(a+1,a+n+1);
        map<int,int>::iterator it,jt,ope;
//	for(it = f.begin();it!=f.end();it++)
  //            cout<<it->first<<' '<<it->second<<endl;
//	cout<<endl;
	int mpflag = 1,fflag = 1;
	while(mpflag&&fflag) {
		mpflag = 0,fflag = 0;
		for(it = mp.begin(),jt = f.begin(),jt++;it!=mp.end()&&jt!=f.end();it++,jt++) {
			ope = it;
	//		if(jt==f.end())	break;
			int tmp = ope->second;
//			cout<<ope->first<<' '<<ope->second<<"    "<<jt->first<<' '<<jt->second<<"   "<<mp[jt->first]<<endl;
			ope->second -= max((int)0,jt->second),ope->second = max(ope->second,(int)0);
			f[ope->first] -= max((int)0,jt->second),f[ope->first] = max((int)0,f[ope->first]);
			jt->second -= max((int)0,tmp),jt->second = max(jt->second,(int)0);
		}
		
		for(it = mp.begin();it!=mp.end();it++)
			if(it->second) {
				mpflag = 1;
				break;
			}
		for(it = f.begin(),it++;it!=f.end();it++)
			if(it->second) {
				fflag = 1;
				break;
			}
				
		cp.clear();
		for(it = mp.begin();it!=mp.end();it++)
			if(it->second)
				cp[it->first] = it->second;
		mp.clear();
		for(it = cp.begin();it!=cp.end();it++)
          	      mp[it->first] = it->second;

		cp.clear();
                for(it = f.begin();it!=f.end();it++)
                        if(it->second)
                                cp[it->first] = it->second;
                f.clear();
                for(it = cp.begin();it!=cp.end();it++)
                      f[it->first] = it->second;
//		for(it = mp.begin();it!=mp.end();it++)
//			cout<<it->first<<' '<<it->second<<endl;
//		cout<<endl;
//		for(it = f.begin();it!=f.end();it++)
//			cout<<it->first<<' '<<it->second<<endl;
//		cout<<"_________"<<endl;
	}
	int ans = 0;
	for(it = mp.begin();it!=mp.end();it++)  {
		if(it->second)
			ans += it->second;
//		cout<<it->first<<' '<<it->second<<endl;
	}
//	cout<<endl;
//	for(it = f.begin();it!=f.end();it++)
//		cout<<it->first<<' '<<it->second<<endl;
	cout<<ans<<endl;
	return 0;
}
