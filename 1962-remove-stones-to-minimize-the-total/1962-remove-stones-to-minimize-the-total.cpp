class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n= piles.size();
        priority_queue<pair<int, int>>pq;
        for(int i=0 ; i< n ; i++){
            pq.push({piles[i] , i});
        }
        while( k--){
            auto t= pq.top() ; pq.pop();
            int ele = t.first;
            int idx = t.second;
            pq.push({ele-floor(ele/2) , idx});
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top().first;
            pq.pop();
        }
        return sum;
    }
};