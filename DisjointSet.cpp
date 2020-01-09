 /*
 ----Created by Chivas----
 1. disjoint-set data structure
 2. union-find algorithm 
 3. Find: determine which subset the element is in
 		  determine if two elements are in the same subset
 4. Union: join two subsets into a single subset
 5. detect cycle in an undirected graph
 6. one operation: O(a(n)) <O(log(n))
 ----2019/09/24----
 */
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 #define MAX_N 10000 
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
 
 int main() {
 	
 	return 0;
 }
