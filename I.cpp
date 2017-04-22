/*
	Author: Hamza Hasbi
	Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
	Date: 19/04/2017 13:52:56
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
inline gcd(ll a,ll b) {return 1LL*b == 0 ? a : gcd(1LL*b, a*1LL % b*1LL);}
using namespace std;

main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	scanf("%d",&n);
	vector<int> ans;
	int curr=0;
	
	for(int i=0;i<n;i++){
		int a;
		curr=0;
		int best=1;
		map<int,int>mp;
		for(int j=0;j<n;j++){
			scanf("%d",&a);
			best=max(a,best);
			for(int k=1;k<=sqrt(a);k++) {
				if(a%k==0 ) mp[k]++,mp[a/k]++;
			}
		}
		for(int k=1;k<=sqrt(best);k++) 
			if(mp[k]>=n) {
				curr=k;		
		}
		ans.push_back(curr);
	}
	for(int i=0;i<n-1;i++) cout<<ans[i]<<" ";
	cout<<ans[n-1]<<endl;
	return 0;
}
