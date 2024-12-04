#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class SocialNetwork
{
public:
    unordered_map<string, unordered_set<string>> friendships;

    void addFriendship(const string &user1, const string &user2)
    {
        friendships[user1].insert(user2);
        friendships[user2].insert(user1);
    }

    vector<string> recommendFriends(const string &user)
    {
        unordered_set<string> recommended;

        if (friendships.find(user) == friendships.end())
        {
            cout << "User not found!" << endl;
            return {};
        }

        for (const auto &friendName : friendships[user])
        {
            for (const auto &mutualFriend : friendships[friendName])
            {
                if (mutualFriend != user && friendships[user].find(mutualFriend) == friendships[user].end())
                {
                    recommended.insert(mutualFriend);
                }
            }
        }

        vector<string> result(recommended.begin(), recommended.end());
        return result;
    }

    void printAllFriends()
    {
        for (const auto &user : friendships)
        {
            const string &currentUser = user.first;
            cout << currentUser << "'s friends: ";
            for (const auto &friendName : user.second)
            {
                cout << friendName << " ";
            }
            cout << endl;
        }
    }

    void printFriendRecommendations()
    {
        cout << "\nFriend Recommendations:" << endl;
        for (const auto &user : friendships)
        {
            const string &currentUser = user.first;
            vector<string> recommendations = recommendFriends(currentUser);
            cout << "Friend Recommendations for " << currentUser << ": ";
            for (const auto &rec : recommendations)
            {
                cout << rec << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    auto start = high_resolution_clock::now();
    SocialNetwork sn;

    bool check = false;
    char choice;
    
    string friend1;
    string friend2;

    while(!check){
         if(check==true)
            break;
         cout<<"Add Friends(y/n) : ";
         cin>>choice;
         if(choice=='y' || choice=='Y'){
             cout<<"Enter 1st Friend name : "
             getline(cin,friend1);
             cout<<"Enter 2nd Friend name : "
             getline(cin,friend2);
             sn.addFriendship(friend1,friend2);
         }
         else if(choice =='n' || choice =='N')
             check = true;
         else
             cout<<"Invalid input, Try again!";
    }
    
    sn.printAllFriends();
    sn.printFriendRecommendations();
    auto stop = high_resolution_clock::now();
    auto time = duration_cast<millisecond>(start-stop);
    cout<<"Time taken for finding recommended friends :"<<time.count()<<endl;

    return 0;
}
