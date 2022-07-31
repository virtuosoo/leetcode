#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;


struct foodNode {
    string name;
    int rating;

    bool operator< (const foodNode &rhs) const {
        if (rhs.rating != rating) {
            return rating < rhs.rating;
        } else {
            return name > rhs.name;
        }
    }

    // friend bool operator< (const foodNode &a, const foodNode &b) {
    //     if (a.rating != b.rating) {
    //         return a.rating < b.rating;
    //     } else {
    //         return a.name > b.name;
    //     }
    // }
};

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            string &name = foods[i], &cuisine = cuisines[i];
            int rating = ratings[i];

            foodNode node{name, rating};
            foodmap[cuisine].insert(node);
            ratingmap[name] = rating;
            cuisinemap[name] = cuisine;
        }
    }
    
    void changeRating(string food, int newRating) {
        foodNode tmp{food, ratingmap[food]};
        foodNode now{food, newRating};
        auto it = foodmap[cuisinemap[food]].find(tmp);
        foodmap[cuisinemap[food]].erase(it);

        foodmap[cuisinemap[food]].insert(now);
        ratingmap[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return foodmap[cuisine].rbegin()->name;
    }

    map<string, set<foodNode> > foodmap;
    map<string, int> ratingmap;
    map<string, string> cuisinemap;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

int main()
{
    priority_queue<int>  q;
}