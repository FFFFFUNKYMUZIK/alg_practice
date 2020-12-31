class UndergroundSystem {

	template <typename T1, typename T2>
	using hash = unordered_map<T1, T2>;

	using timeinfo = struct {int cnt; double sumtime;};
	using dpt = struct {string from; int time;};

public:

	hash<int, dpt> onboard;
	hash<string, hash<string, timeinfo>> avg;

    UndergroundSystem() {
        onboard.clear();
        avg.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        onboard[id] = {stationName, t};
        if (avg.find(stationName) == avg.end())
        	avg[stationName] = hash<string, timeinfo>();
    }
    
    void checkOut(int id, string stationName, int t) {
        string from = onboard[id].from;
        int dept = onboard[id].time;
        onboard.erase(id);

        if (avg[from].find(stationName) != avg[from].end()){
        	avg[from][stationName].cnt++;
        	avg[from][stationName].sumtime += (t-dept);
        }
        else{
        	avg[from][stationName] = {1, (double)t-dept};
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        if (avg.find(startStation) != avg.end()	&&
        	avg[startStation].find(endStation) != avg[startStation].end()){
        	return avg[startStation][endStation].sumtime / avg[startStation][endStation].cnt;
        }
        else{
        	return 0.0;
        }
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */