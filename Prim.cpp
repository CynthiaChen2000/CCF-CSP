 /*
 ----Created by Chivas----
 1. Prim algorithm
 2. MST: Minimum Spanning Tree
 3. it's a Greedy Algorithm
 4. O(V^2)
 ----2019/09/27----
 */
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 #define MAX_V 10000
 #define INF 100000000
 int V;
 int cost[MAX_V][MAX_V];
 int mincost[MAX_V];
 bool used[MAX_V];
 
 int prim() {
 	for(int i=0;i<V;i++) {
 		mincost[i]=INF;
 		used[i]=false;
	}
	mincost[0]=0;
	int res=0;
	
	while(true) {
		int v=-1;
		for(int u=0;u<V;u++) {
			if(!used[u]&&(v==-1||mincost[u]<mincost[v])) v=u;
		}
		if(v==-1) break;
		used[v]=true;
		res+=mincost[v];
		for(int u=0;u<V;u++) {
			mincost[u]=min(mincost[u],cost[v][u]);
		}
	}
	return res;
 }
 
 int main() {
 	
 	return 0;
 }
