/**
 * problem : https://leetcode.com/problems/design-a-food-rating-system/
 * time complexity : O(NlogN) // N = foods
 * data structure : set, map
 */
 
class FoodRatings {
    struct compare{
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        }
    };
    
    // priority_queue<pair<int, string>> pq;
    unordered_map<string, int> ratingMap;
    unordered_map<string, string> cDict;
    unordered_map<string, set<pair<int, string>>> ansDict;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0; i<foods.size(); i++){
            ratingMap[foods[i]] = ratings[i];
            ansDict[cuisines[i]].insert({-ratings[i], foods[i]});
            cDict[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cs = cDict[food];
        ansDict[cs].erase({-ratingMap[food], food});   
        ratingMap[food] = newRating;
        ansDict[cs].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return ansDict[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
