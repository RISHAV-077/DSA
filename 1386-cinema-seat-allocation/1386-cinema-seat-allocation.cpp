class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for (auto& reservedSeat : reservedSeats) {
            int row = reservedSeat[0];
            int seat = reservedSeat[1];

            mp[row].insert(seat);
        }
        int result = (n - mp.size()) * 2;
        for (auto& [row, bookedSeats] : mp) {
            auto isav = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool graupA = isav(2) && isav(3) && isav(4) & isav(5);
            bool graupB = isav(4) && isav(5) && isav(6) & isav(7);
            bool graupC = isav(6) && isav(7) && isav(8) & isav(9);

            if (graupA && graupC)
                result += 2;
            else if (graupA || graupB || graupC)
                result += 1;
        }

        return result;
    }
};
