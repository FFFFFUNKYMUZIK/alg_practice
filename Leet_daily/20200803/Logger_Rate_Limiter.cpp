class Logger {
public:
    
    unordered_map<string, int> rec;
    
    /** Initialize your data structure here. */
    Logger() {
        unordered_map<string, int>().swap(rec);
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        
        if (rec.find(message) == rec.end()){
            rec[message] = timestamp;
            cout<<message;
            return true;
        }
        else if (rec[message] + 10 <= timestamp){
            rec[message] = timestamp;
            cout<<message;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */