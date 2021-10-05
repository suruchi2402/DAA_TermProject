//   Header file for CPP, It is recommended to use C++ 11 in Code Block editor because i have
// used auto here , I have compiled and ran all my code in CodeBlock.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	stack< int > s;

           // For ordering the vertices in decreasing order of finish time in DFS.
	void dfs(int cur,bool *vis,vector<int> adj[]){
	    vis[cur]=1;
	    for(auto x:adj[cur]){
	        if(!vis[x])
	        dfs(x,vis,adj);
	    }
	    s.push(cur);
	}

	void sdfs(int cur,bool *vis,vector<int> adj[]){
	    vis[cur]=1;
                for(auto x:adj[cur]){
	        if(!vis[x])
	        dfs(x,vis,adj);
	    }
	}

   //Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // this answer variable will store total number of strongly connected subgraph in graph
       int answer = 0;
        bool vis[V] = {0};
        for(int i=0;i<V;++i){
            if(!vis[i])
            dfs(i,vis,adj);
        }

        vector<int> rev[V];
        for(int i=0;i<V;++i){
            for(auto x:adj[i]){
                rev[x].push_back(i);
            }
        }

       // function to set value of all visited vector to 0
        memset(vis,0,sizeof(vis));
        while(s.empty()==false){
            int i=s.top();
            s.pop();
            if(!vis[i]){
            sdfs(i,vis,rev);
            ++answer;
            }
        }
        return answer;
    }
};

// Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    //Here t stands for total number of test cases
    while(t--)
    {
    	int Vertex, Edge;
    	cin >> Vertex >> Edge;
           // creating adjacency list (for graph creation)
    	vector<int> adj[Vertex];
    	for(int i = 0; i < Edge; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}
            // creating object that will call and access the public member of solution class
    	Solution obj;
    	cout << obj.kosaraju(Vertex, adj) << "\n";
    }
    return 0;
}
// Driver class ends.
