class Solution {
public:
    vector<int> res;
    bool flag = false;

    void dfs(vector<vector<int>>& g, vector<bool>& v, vector<bool>& vi, int n) {
        v[n] = true;
        vi[n] = true;

        for(auto next : g[n]) {
            if(!v[next]) {
                dfs(g, v, vi, next);
            }
            else if(vi[next]) {
                flag = true;
            }
        }

        vi[n] = false;
        res.push_back(n);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> visiting(numCourses, false);

        vector<vector<int>> graph(numCourses);

        for(auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                dfs(graph, vis, visiting, i);
            }
        }

        reverse(res.begin(), res.end());

        return flag == true ? vector<int>(0) : res;
    }
};
