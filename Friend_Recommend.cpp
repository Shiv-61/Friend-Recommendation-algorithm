#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

class SocialNetwork
{
private:
    unordered_map<int, unordered_set<int>> adjList;

public:
    void addFriendship(int user1, int user2)
    {
        adjList[user1].insert(user2);
        adjList[user2].insert(user1);
    }

    // Get friend recommendations for a user
    vector<int> getFriendRecommendations(int user)
    {
        vector<int> recommendations;
        unordered_set<int> visited;
        queue<int> q;

        // Mark the user and their direct friends as visited
        visited.insert(user);
        for (int friendID : adjList[user])
        {
            visited.insert(friendID);
            q.push(friendID);
        }

        // BFS traversal to find friends of friends
        while (!q.empty())
        {
            int currentFriend = q.front();
            q.pop();

            // Check friends of the current friend
            for (int friendOfFriend : adjList[currentFriend])
            {
                if (visited.find(friendOfFriend) == visited.end())
                {
                    recommendations.push_back(friendOfFriend);
                    visited.insert(friendOfFriend); // Mark as visited
                }
            }
        }

        return recommendations;
    }
};

// Helper function to display recommendations
void displayRecommendations(int user, const vector<int> &recommendations)
{
    cout << "Friend recommendations for user " << user << ": ";
    if (recommendations.empty())
    {
        cout << "No recommendations available." << endl;
    }
    else
    {
        for (int rec : recommendations)
        {
            cout << rec << " ";
        }
        cout << endl;
    }
}

// Main function
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    SocialNetwork sn;

    // Adding some friendships to the social network
    sn.addFriendship(1, 2);
    sn.addFriendship(1, 3);
    sn.addFriendship(2, 4);
    sn.addFriendship(2, 5);
    sn.addFriendship(3, 6);
    sn.addFriendship(5, 6);
    sn.addFriendship(4, 7);

    // Get friend recommendations for a specific user
    int user = 1;
    vector<int> recommendations = sn.getFriendRecommendations(user);

    displayRecommendations(user, recommendations);

    return 0;
}
