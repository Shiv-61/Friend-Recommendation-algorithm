#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

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
    SocialNetwork sn;

    bool check = false;
    char choice;
    
    string friend1;
    string friend2;
   
    sn.printAllFriends();
    sn.printFriendRecommendations();

    return 0;
}
