 /*
 ----Created by Chivas----
 1. Floyd-Warshall algorithm 
 2. All Pairs Shortest Path problem 
 3. can work with graphs in which edges have negative weights
 4. Using Sliding Array to reduce space complexity
 5. O(V^3)
 ----2019/09/26----
 */
 #include <cstdio>
 #include <algorithm>
 using namespace std;
 #define MAX_V 10000
 #define INF 100000000
 
 int d[MAX_V][MAX_V];
 int V;
 
 void FloydWarshall() {	
	for(int k=0;k<V;k++) {
		for(int i=0;i<V;i++) {
			for(int j=0;j<V;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][i]);
		} 
	}
 }
 
 int main () {
 	for(int i=0;i<V;i++) {
		fill(d[i], d[i]+V, INF);
		d[i][i]=0;
	}
	/* d[i][j]=w[i][j] */
	FloydWarshall();
	
 	return 0;
 }
