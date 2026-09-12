class Solution {
public:
    struct Compare {
        bool operator()(pair<char, int> a, pair<char, int> b) {
            if (a.first != b.first)
                return a.first > b.first; 

            return a.second < b.second;  
        }
    };

    string clearStars(string s) {
        int n = s.length();

        priority_queue<pair<char, int>,vector<pair<char, int>>,Compare> pq;
        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            }
            else {
                pq.pop();
            }
        }
        string ans(n, ' ');
        while (!pq.empty()) {
            auto [ch, index] = pq.top();
            pq.pop();
            ans[index] = ch;
        }

        string result = "";

        for (char c : ans) {
            if (c != ' ')
                result += c;
        }

        return result;
    }
};