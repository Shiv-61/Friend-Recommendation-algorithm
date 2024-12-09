# Friend-Recommendation-algorithm
The Social Network Friend Recommendation System is a C++ implementation that simulates a basic social network where users can be friends with each other. The project uses graph theory to represent users as nodes and friendships as edges. The goal of the system is to recommend potential friends to a user based on the concept of "friends of friends."
# Social Network Friend Recommendation System
This project is a simple social network friend recommendation system implemented in C++. It uses a graph structure to model friendships and recommends new friends to a user based on the concept of "friends of friends."
## Project Overview
The social network is represented using an adjacency list, where each user is a node in the graph, and friendships are edges connecting these nodes. For a given user, the system recommends friends who are two steps away in the network (i.e., friends of friends), but are not directly connected.
## Features

- **Add Friendships**: Add mutual friendships between users in the network.
- **Friend Recommendations**: Get friend recommendations based on two-degree connections.
- **Efficient Traversal**: Uses Breadth-First Search (BFS) to traverse the network and find friend recommendations.

## Getting Started

### Prerequisites

- C++ compiler (e.g., GCC, Clang)
- Basic knowledge of C++ and data structures

### Installation

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/Shiv-61/social-network-friend-recommendation.git

2. Compile the code:
   ```bash
   g++ -o friend_recommendation main.cpp
   ```
3. Run the executable:
   ```bash
   ./friend_recommendation
   ```
