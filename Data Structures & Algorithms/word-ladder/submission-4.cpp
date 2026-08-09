class Solution {
public:
    int diff(string w1, string w2) {
        int ctr = 0;
        for(int i = 0; i < w1.size(); i++) {
            if(w1[i] != w2[i]) ctr++;
        }
        return ctr;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool in_list = false;        
        wordList.insert(wordList.begin(), beginWord);
        vector<vector<int>> adj(wordList.size());
        vector<bool> vis(wordList.size(), false);

        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord) in_list = true;

            for(int j = i + 1; j < wordList.size(); j++) {
                if(diff(wordList[i], wordList[j]) == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        if(!in_list) return 0;

        queue<int> q;
        vis[0] = true;
        q.push(0);
        int ctr = 1;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();

                if(wordList[node] == endWord) return ctr;

                for(auto n : adj[node]){
                    if(!vis[n]) { 
                        vis[n] = true;
                        q.push(n);
                    }
                }
            }

            ctr++;
        }

        return 0;
    }
};
