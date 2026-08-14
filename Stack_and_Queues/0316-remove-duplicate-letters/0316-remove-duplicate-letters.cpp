class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26,0);
        vector<bool> vis(26,false);
        string ans = "";

        for(int i = 0;i < s.size();i++){
            freq[s[i] - 'a'] = i;
        }

        for(int i = 0;i < s.size();i++){
                while(!vis[s[i] - 'a'] && !ans.empty() && ans.back() > s[i] && freq[ans.back() - 'a'] > i){
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }
           
           if(vis[s[i] - 'a'] == false){
            ans += s[i]; 
             vis[s[i] - 'a'] = true;
           }
        }

        return ans;
    }
};
