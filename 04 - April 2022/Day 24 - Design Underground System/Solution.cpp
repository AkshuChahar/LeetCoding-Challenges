class UndergroundSystem {
public:
    // Initialise 2 maps.
    // One map keeps track of passenger's check-in station and time.
    unordered_map<int, pair<string, int>> boarding;
    // Second map keeps track of total time between two stations and the number of passengers.
    unordered_map<string, pair<int, int>> total_time;

    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
        // Add the passenger to 'boarding'.
        boarding[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t) {
        // Get the check-in time and station for the passenger.
        string station = boarding[id].first;
        int start_time = boarding[id].second;
        // Make a key for storing the total time.
        string key = station + ":" + stationName;
        // Check if we have previously dealt with the same stations.
        if (total_time.find(key) != total_time.end()) {
            // Add the time taken and increment the count of passengers.
            total_time[key].first += t - start_time;
            total_time[key].second++;
        }
        // Else add the data to map.
        else
            total_time[key] = make_pair(t - start_time, 1);
        // Delete the passenger from 'boarding'.
        boarding.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        // Make the key for 'total_time'.
        string key = startStation + ":" + endStation;
        return (double)total_time[key].first / (double)total_time[key].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */