 /*
 ----Created by Chivas----
 1. Printing Paths in Dijkstra¡¯s Shortest Path Algorithm
 2. O(V)
 ----2019/09/26----
 */
 #include <cstdio>
 #include <vector>
 #include <queue>
 #include <algorithm>
 using namespace std;
 #define MAX_V 10000
 #define INF 100000000
 struct edge {
 	int to, cost;
 };
 typedef pair<int, int> P;
 
 vector<edge> G[MAX_V];
 int d[MAX_V],prev[MAX_V];
 int V;
 
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que; // Don't forget the space key!
	fill(d, d+V, INF);
	fill(prev, prev+V, -1);
	d[s]=0;
	que.push(P(0,s));
	
	while(!que.empty()) {
		P p=que.top();
		que.pop();
		int v=p.second;
		if(d[v]<p.first) continue; // d[v] had been updated, p should be abandoned.
		for(int i=0;i<G[v].size();i++) {
			edge e=G[v][i];
			if(d[e.to]>d[v]+e.cost) {
				d[e.to]=d[v]+e.cost;
				prev[e.to]=v;
				que.push(P(d[e.to],e.to));
			}
		}
	} 
}

vector<int> get_path(int t) {
	vector<int> path;
	for(;t!=-1;t=prev[t]) path.push_back(t);
	reverse(path.begin(),path.end());
	return path;
}
 
 int main () {
 	
 	return 0;
 }
