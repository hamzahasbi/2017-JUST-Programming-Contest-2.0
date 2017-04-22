/*
	Author: Hamza Hasbi
	Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
	Date: 20/04/2017 22:21:26
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define uld unsigned long double
#define ui unsigned int
#define ud unsigned double
#define uf unsigned float
#define pi 2*acos(0.0)
#define module cin.ignore()
#define rep(i,l,r) for(auto i=l;i<=r;i++)
#define range(x,y) for(auto x:y)
//inline lcm(int a,int b) {return a*b/__gcd(a,b);}
//inline gcd(ll a,ll b) {return 1LL*b == 0 ? a : gcd(1LL*b, a*1LL % b*1LL);}
using namespace std;

main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin>>s;
	unordered_map<char,int>mp;
	int mx=-1;
	rep(i,0,s.size()-1){
		mp[s[i]]++;
		mx=max(mx,mp[s[i]]);
	}
	int ans=-1;
	long long mn=LLONG_MAX;
	for(int i=2;i<=mx+1;i++)
	{
		long long sum=0;
		for(char k='a';k<='z';k++){
			sum+=(long long )(mp[k]%i)*mp[k];
		}
		if(sum<mn){
			mn=sum;
			ans=i;
			if(sum==0) break;
		}
	}
	cout<<ans<<endl;
	return 0;
}
