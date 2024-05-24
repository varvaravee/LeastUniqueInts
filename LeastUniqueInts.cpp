class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        //declare and initialize unordered map
        unordered_map<int, int> freq;
        for (auto& num : arr)
            freq[num]++;
        //prio queue stores vectors, where each vector contains two elements
          priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (auto& [num, f] : freq) 
            pq.push({f, num});
        
        //remove k elements
        while (k>0) {
            auto& top = pq.top();
            int f = top[0], num = top[1];
            pq.pop();

            if (k >= f){
                    k-=f;
            }

            else {
                k=0;
                pq.push({f-k, num});
            }
        }
        
        return pq.size();


        
    }
};
