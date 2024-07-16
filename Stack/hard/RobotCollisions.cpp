// 2751. Robot Collisions
// Solved
// Hard
// Topics
// Companies
// Hint

// There are n 1-indexed robots, each having a position on a line, health, and movement direction.

// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

// All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

// If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

// Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

// Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

// Note: The positions may be unsorted.
 

 

// Example 1:

// Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
// Output: [2,17,9,15,10]
// Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

// Example 2:

// Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
// Output: [14]
// Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].

// Example 3:

// Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
// Output: []
// Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].

 

// Constraints:

//     1 <= positions.length == healths.length == directions.length == n <= 105
//     1 <= positions[i], healths[i] <= 109
//     directions[i] == 'L' or directions[i] == 'R'
//     All values in positions are distinct

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 106.3K
// Submissions
// 185.7K
// Acceptance Rate
// 57.3%

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        vector<pair<int, pair<int, pair<int, int>>>> robots;

        for (int idx = 0; idx < n; idx++) {
            robots.push_back({positions[idx], {healths[idx], {directions[idx], idx}}});
        }

        sort(robots.begin(), robots.end());

        stack<int> st;

        for (int idx = 0; idx < n; idx++) {
            bool flag = true;

            while (!st.empty() && robots[st.top()].second.second.first == 'R' && robots[idx].second.second.first == 'L') {
                flag = false;

                if (robots[st.top()].second.first == robots[idx].second.first) {
                    st.pop();
                    break;
                }
                else if (robots[st.top()].second.first > robots[idx].second.first) {
                    robots[st.top()] = {robots[st.top()].first, {robots[st.top()].second.first - 1, robots[st.top()].second.second}};                   
                    break;
                }
                else {
                    st.pop();
                    robots[idx] = {robots[idx].first, {robots[idx].second.first - 1, robots[idx].second.second}};

                    if (st.empty() || !(robots[st.top()].second.second.first == 'R' && robots[idx].second.second.first == 'L')) {
                        st.push(idx);

                        break;
                    }
                }
            }

            if (flag) {
                st.push(idx);
            }
        }

        vector<pair<int, int>> temp;

        while (!st.empty()) {
            temp.push_back({robots[st.top()].second.second.second, robots[st.top()].second.first});
            st.pop();
        }

        sort(temp.begin(), temp.end());

        vector<int> ans;

        for (auto p : temp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};

// // 11 16 44
// // 1 17 20
// // RRL

// class Solution:
//     def survivedRobotsHealths(self, positions: List[int], healths: List[int], directions: str) -> List[int]:
//         n = len(positions)

//         robots = []

//         for idx in range(n):
//             robots.append([positions[idx], healths[idx], directions[idx], idx])
        
//         robots = sorted(robots, key = lambda x : x[0])

//         st = []

//         for idx in range(n):
//             flag = True

//             while len(st) > 0 and robots[st[-1]][2] == 'R' and robots[idx][2] == 'L':
//                 flag = False

//                 if robots[st[-1]][1] == robots[idx][1]:
//                     st.pop()
//                     break
//                 elif robots[st[-1]][1] > robots[idx][1]:
//                     robots[st[-1]][1] -= 1
//                     break
//                 else:
//                     st.pop()
//                     robots[idx][1] -= 1

//                     if len(st) == 0 or (robots[st[-1]][2] == 'R' and robots[idx][2] == 'L') == False:
//                         st.append(idx)
//                         break
            
//             if flag:
//                 st.append(idx)
        
//         temp = []

//         for idx in st:
//             temp.append([robots[idx][3], robots[idx][1]])
        
//         temp = sorted(temp, key = lambda x : x[0])

//         ans = [x[1] for x in temp]

//         return ans