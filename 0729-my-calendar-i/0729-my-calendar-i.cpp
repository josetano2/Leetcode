class MyCalendar {
public:
    vector<pair<int, int>> events;
    bool book(int start, int end) {
        int len = events.size();
        for(int i = 0; i < len; i++){
            if(end > events[i].first && start < events[i].second){
                return false;
            }
        }
        events.push_back(make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */