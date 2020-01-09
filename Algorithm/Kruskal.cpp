 /*
 ----Created by Chivas----
 1. Kruskal algorithm
 2. MST: Minimum Spanning Tree
 3. using Union-Find algorithm to detect cycle
 4. it's a Greedy Algorithm
 5. O(ElogV)
 ----2019/09/25----
 */
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 #define MAX_N 10000
 #define MAX_E 100000 
 struct edge {
 	int u,v,cost;
 };
 
 edge es[MAX_E];
 int V,E;
 int par[MAX_N];
 int rank[MAX_N];
 
 void init(int n) {
 	for(int i=0;i<n;i++) {
 		par[i]=i;
 		rank[i]=0;
	}
 }
 
 int find(int x) {
 	if(par[x]==x) return x;
 	else return par[x]=find(par[x]);
 }
 
 void unite(int x,int y) {
 	x=find(x);
 	y=find(y);
 	if(x==y) return;
 	
 	if(rank[x]<rank[y]) par[x]=y;
 	else {
 		par[y]=x;
 		if(rank[x]==rank[y]) rank[x]++;
	}
 }
 
 bool same(int x,int y) {
 	return find(x)==find(y);
 }
 
 bool comp(const edge& e1,const edge& e2) {
 	return e1.cost<e2.cost;
 }
 
 int kruskal() {
 	sort(es,es+E,comp);
 	init(V);
 	int res=0;
 	for(int i=0;i<E;i++) {
 		edge e=es[i];
 		if(!same(e.u,e.v)) {
 			unite(e.u,e.v);
 			res+=e.cost;
		 }
	 }
 }
 
 int main() {
 	
 	return 0;
 }
