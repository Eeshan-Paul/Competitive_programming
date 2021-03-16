#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isCyclic(int V, vector<int> adj[]) {
        int indegree[V]={0};
        for (int u=0;u<V;u++){
            for (int v:adj[u])
            indegree[v]++;
        }
        int count=-1;
        for (int i=0;i<V;i++){
            if (indegree[i]==0){
                count=i;
            }
        }
        if (count==-1)
            return true;
        queue<int>q;
        q.push(count);
        int c=0;
        while (!q.empty()){
            int u=q.front();
            q.pop();
            c++;
            for(int v:adj[u]){
                indegree[v]--;
                if (indegree[v]==0)
                    q.push(v);
            }
        }
        return (c!=V);
	}
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}