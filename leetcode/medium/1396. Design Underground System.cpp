/**
 * problem : https://leetcode.com/problems/design-underground-system/
 * data structure : map
 */
 
class UndergroundSystem {
public:
    // key = "startStation,endStation", value = [count, sum]
    unordered_map<string, pair<int, double>> stations; 
    // key = id, value = [startStation, startTime]
    unordered_map<int, pair<string,int>> people;
    
    UndergroundSystem() {
        stations = unordered_map<string, pair<int, double>>();
        people = unordered_map<int, pair<string,int>>();
    }
    
    void checkIn(int id, string stationName, int t) {
        people[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        double diff = t - people[id].second; 
        string key = people[id].first + "," + stationName;
        people.erase(id);
        if(stations.count(key)){
            stations[key] = {stations[key].first + 1, stations[key].second + diff};
        } else {
            stations[key] = {1, diff};
        }
    } 
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        if(stations.count(key))
            return stations[key].second / stations[key].first;
        return 0;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
