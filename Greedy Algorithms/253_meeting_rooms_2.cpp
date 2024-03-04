class Solution {
public:
    static bool customCompare(const pair<int, bool>& a, const pair<int, bool>& b){
        if (a.first != b.first){
            return a.first < b.first;
        }else{
            return a.second < b.second;
        }

    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int numRooms = 1;
        int meetings = 0;

        vector<pair<int, bool>> meetingSchedule;

        for (auto it: intervals){
            meetingSchedule.push_back(make_pair(it[0], true));
            meetingSchedule.push_back(make_pair(it[1], false));
        }

        sort(meetingSchedule.begin(), meetingSchedule.end(), customCompare);

        for (const auto& pair: meetingSchedule){
            if (pair.second == true){
                meetings += 1;
                if (numRooms < meetings){
                    numRooms = meetings;
                }
            }else{
                meetings -= 1;
            }
        }

        return numRooms;      
    }
};