#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class SocialNetwork {
public:
    unordered_map<string, unordered_set<string>> friendships;

    void addFriendship(const string& user1, const string& user2) {
        friendships[user1].insert(user2);
        friendships[user2].insert(user1);
    }

    vector<string> recommendFriends(const string& user) {
        unordered_set<string> recommended;

        if (friendships.find(user) == friendships.end()) {
            cout << "User not found!" << endl;
            return {};
        }

        for (const auto& friendName : friendships[user]) {
            for (const auto& mutualFriend : friendships[friendName]) {
                if (mutualFriend != user && friendships[user].find(mutualFriend) == friendships[user].end()) {
                    recommended.insert(mutualFriend);
                }
            }
        }

        vector<string> result(recommended.begin(), recommended.end());
        return result;
    }

    void printFriends(const string& user) {
        if (friendships.find(user) != friendships.end()) {
            cout << user << "'s friends: ";
            for (const auto& friendName : friendships[user]) {
                cout << friendName << " ";
            }
            cout << endl;
        } else {
            cout << "User not found!" << endl;
        }
    }
};

int main() {
    SocialNetwork sn;

    sn.addFriendship("Alice", "Bob");
    sn.addFriendship("Alice", "Charlie");
    sn.addFriendship("Bob", "Charlie");
    sn.addFriendship("Bob", "David");
    sn.addFriendship("Charlie", "Eve");

    sn.printFriends("Alice");

    vector<string> recommendations = sn.recommendFriends("Alice");

    cout << "Friend Recommendations for Alice: ";
    for (const auto& rec : recommendations) {
        cout << rec << " ";
    }
    cout << endl;

    return 0;
}
