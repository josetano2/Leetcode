class Car{
public:

    int position, speed;
    float time;
    

    Car(int p, int s, int t){
        position = p;
        speed = s;
        time = (t - p) / float(s);
    }
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int len = position.size();
        
        // if(len == 1){
        //     return len;
        // }

        vector<Car> cars;
        
        stack<Car> fleets;

        for(int i = 0; i < len; i++){
            cars.push_back(Car(position[i], speed[i], target));
        }

        sort(cars.begin(), cars.end(), [](const Car& a, const Car& b){
            return a.position < b.position;
        });

        // for(auto x : cars){
        //     cout << x.position << " " << x.speed << " " << x.time << endl;
        // }

        for(int i = len - 1; i >= 0; i--){
            if(fleets.empty()){
                fleets.push(cars[i]);
                continue;

            }
            cout << fleets.top().time << " " << cars[i].time << endl;
            if(fleets.top().time < cars[i].time){
                fleets.push(cars[i]);
            }
        }

        return fleets.size();
    }
};