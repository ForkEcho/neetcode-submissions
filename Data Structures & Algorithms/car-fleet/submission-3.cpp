class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());
        double ttt = (double)(target - pair[0].first) / pair[0].second;
        int sol = 1;
        for (int i = 1; i < pair.size(); i++) {
            double current_ttt = (double)(target - pair[i].first) / pair[i].second;
            if (current_ttt > ttt) {
                ttt = current_ttt;
                sol++;
            }
            
        }
        return sol;
    }
};