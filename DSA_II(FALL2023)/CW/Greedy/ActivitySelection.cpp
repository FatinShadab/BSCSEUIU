/*
You have given information of 'T' tasks, each task data contains 5 informations, those are
            task id (int),
            task name (string),
            task start_time (int),
            task end_time (int)
            task profit (double) [same for every activity]

Show how many activites can you select max and gain max profit.

Input :
==============================
5
1 A 8 9 100
2 B 10 11 100
3 C 9 12 100
4 D 10 13 100
5 E 7 11 100

Output :
==============================
2 200
[Any valid Answer]
*/

#include <bits/stdc++.h>

using namespace std;


class Activity {
    public:
        string name;
        int id;
        int start_time;
        int end_time;
        double profit;

    public:
        Activity() {}

        Activity(string name, int id, int start_time, int end_time, double profit) {
            this->name = name;
            this->id = id;
            this->start_time = start_time;
            this->end_time = end_time;
            this->profit = profit;
        }

        string info() {
            return "Id : " + to_string(this->id)
                    + "\nName : " + this->name
                    + "\nStart Time : " + to_string(this->start_time)
                    + "\nEnd Time : " + to_string(this->end_time)
                    + "\nProfit : " + to_string(this->profit)
                    + "\n";
        }

        static bool comparator(Activity a1, Activity a2) {
            return a1.end_time <= a2.end_time;
        }
};


int main() {

    int number_of_activity;

    printf("Enter the number of activities : ");
    cin >> number_of_activity;

    vector<Activity> activities(number_of_activity);

    int i = 0;
    while (i < number_of_activity) {
        activities[i] = Activity();

        cin >> activities[i].id;
        cin >> activities[i].name;
        cin >> activities[i].start_time;
        cin >> activities[i].end_time;
        cin >> activities[i].profit;

        i++;
    }

    sort(activities.begin(), activities.end(), Activity::comparator);

    vector<Activity> pickedActivities;

    pickedActivities.push_back(activities[0]);
    int free_to_take_at = activities[0].end_time;

    for (int idx = 1; idx < activities.size(); idx++) {
        if (activities[idx].start_time >= free_to_take_at) {
            pickedActivities.push_back(activities[idx]);
            free_to_take_at = activities[idx].end_time;
        }
    }
    
    double max_profit = 0;

    for (Activity activity : pickedActivities) {
        max_profit += activity.profit;
        cout << activity.info() << endl;
    }

    cout << "Activity selectd : " << pickedActivities.size() << ", Max profit : " << max_profit << endl;

    return 0;
}