/*
	Author: Hamza Hasbi
	Copyrights: "h.hamza" ==> "www.hamzahasbi.me"
	Date: 21/04/2017 00:35:10
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

unordered_map<int,vector<pair<int,int>>>graph;
bool visited[100005];
int dist[100005];
vector<string>vertices(100005);
int n,m;

int cost(string a,string b){
	bool p[27],t[27];
	
	memset(p,false,sizeof p);
	memset(t,false,sizeof t);
	int ret=0;
	for(auto c:a) 
		p[c-'a']=true;
	
	for(int i=0;i<b.size();i++) if(p[b[i]-'a'] && !t[b[i]-'a']) ret++,t[b[i]-'a']=true;
	
	return ret;
}

void uniform(string &a){
	for(int i=0;i<a.size();i++){
		a[i]=tolower(a[i]);
	}
}
void dijkstra(int node)
{
	dist[node]=0;
	//parent[node]=-1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	pq.push(make_pair(dist[node],node));
	while(!pq.empty())
	{
		int v=pq.top().second;
		pq.pop();
		
		if(visited[v]) continue;
		visited[v]=true;
		
		
		for(auto p:graph[v])
		if(dist[p.first] > dist[v] + p.second){
				dist[p.first] = dist[v] + p.second;
				//parent[p.first]=v;
				pq.push({dist[p.first],p.first});
			}
	}
}

main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	fill(visited,visited+100005,false);
	fill(dist,dist+100005,INT_MAX);
	cin>>n>>m;
	vertices.resize(n);
	for(int i=0;i<n;i++){
		cin>>vertices[i];
		uniform(vertices[i]);
	}
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		graph[v].push_back({u,0});
		graph[u].push_back({v,0});
	}

	for(int i=0;i<n;i++){
		 auto node=vertices[i];
		 //cout<<node<<endl;
		 for(int j=0;j<graph[i].size();j++){
		 	graph[i][j].second=cost(node,vertices[graph[i][j].first]);
		 }
	}
	
	/*for(int i=0;i<n;i++){
		 auto node=vertices[i];
		 //cout<<node<<endl;
		 for(int j=0;j<graph[i].size();j++){
		 	cout<<node<<" "<<vertices[graph[i][j].first]<<" "<<graph[i][j].second<<endl;
		 }
	}*/
	int s,e;
	cin>>s>>e;
	s--;e--;
	dijkstra(s);
	cout<<dist[e]<<endl;
	return 0;
}
