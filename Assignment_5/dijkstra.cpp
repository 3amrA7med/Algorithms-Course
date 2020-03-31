// Program to find Dijkstra's shortest path using 
// priority_queue in STL 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> long longeger Pair 
typedef pair<long long, long long> iPair; 

void addEdge(vector <pair<long long, long long> > graph[], long long u, long long v, long long wt);
void dijkstra(vector<pair<long long,long long> > graph[], long long V, long long src);
 
int main() 
{ 
    
    long long N,M,S,parent,child,weight;
    cin >> N >> M >> S;
    vector<iPair > graph[N];
    for(long long i = 0 ; i < M ;i++)
    {
        cin >> parent >> child >> weight;
        addEdge(graph, parent, child, weight);  
    }
    if(M == 1)
    {
        cout << 2 << " " << weight << endl;
        return 0; 
    }
    if (N == 1)
    {
        cout << 1 << " " << 0 <<endl;
        return 0; 
    }
	dijkstra(graph, N, 0); 

	return 0; 
} 
// To add an edge in the grapgh linked list
// This is a directed graph
void addEdge(vector <pair<long long, long long> > graph[], long long u, long long v, long long wt) 
{ 
	graph[u].push_back(make_pair(v, wt)); 
} 


// Apply Dijkstra algorithm 

void dijkstra(vector<pair<long long,long long> > graph[], long long V, long long src) 
{ 
	// Create a priority queue to store vertices
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	// Create a vector for distances and initialize all as INF
	vector<long long> dist(V, INF); 

	// Insert source and initialize its distance as 0. 
	pq.push(make_pair(0, src)); 
	dist[src] = 0; 

	// loop untio empty
	while (!pq.empty()) 
	{ 
		// The first vertex in pair is the minimum distance vertex, extract it from priority queue. 
		// vertex label is stored in second of pair (it has to be done this way to keep the vertices 
		// sorted distance (distance must be first item in pair) 
		// the min node
        long long u = pq.top().second; 
		pq.pop(); 

		// Get all edges connected to u. 
		for (auto x : graph[u]) 
		{ 
			// Get the node connected to u and their weight
			long long v = x.first;  // node connected to u 
			long long weight = x.second; // their weight

			// If there is shortest path to v through u. 
            // Relaxition of the edge
			if (dist[v] > dist[u] + weight) 
			{ 
				// Updating distance of v 
				dist[v] = dist[u] + weight; 
				pq.push(make_pair(dist[v], v)); 
			} 
		} 
	} 

	// Prlong long shortest distances stored in dist[] 
    long long max = -1;
    long long countOfPlanets = V;
	//prlong longf("Vertex Distance from Source\n"); 
	for (long long i = 0; i < V; ++i) 
    {
		//prlong longf("%d \t\t %d\n", i, dist[i]); 
        if(dist[i] != INF)
        {
            if(dist[i] > max)
                max = dist[i];
        }
        else 
            countOfPlanets--;
        
    }
    cout << endl << countOfPlanets << " " << max << endl;
}
