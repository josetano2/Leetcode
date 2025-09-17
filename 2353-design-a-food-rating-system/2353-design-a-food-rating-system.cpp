class FoodRatings {
public:

    unordered_map<string, set<pair<int, string>>> listOfFoodsBasedOfCuisine;
    unordered_map<string, int> ratingMap;
    unordered_map<string, string> foodCuisineMap;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        // kimchi, miso, sushi
        // korean, japanese, japanese
        // 9, 12, 8

        int len = foods.size();
        
        for(int i = 0; i < len; i++) {
            ratingMap[foods[i]] = ratings[i];
            foodCuisineMap[foods[i]] = cuisines[i];
            listOfFoodsBasedOfCuisine[cuisines[i]].insert({ -ratings[i], foods[i] });
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisineMap[food];

        listOfFoodsBasedOfCuisine[cuisine].erase(listOfFoodsBasedOfCuisine[cuisine].find({ -ratingMap[food], food }));
        ratingMap[food] = newRating;
        listOfFoodsBasedOfCuisine[cuisine].insert({ -newRating, food });

    }
    
    string highestRated(string cuisine) {
        return listOfFoodsBasedOfCuisine[cuisine].begin()->second;
    }
};