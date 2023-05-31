// 690. Employee Importance
// Medium
// 1.9K
// 1.3K
// Companies

// You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

// You are given an array of employees employees where:

//     employees[i].id is the ID of the ith employee.
//     employees[i].importance is the importance value of the ith employee.
//     employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.

// Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.

 

// Example 1:

// Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
// Output: 11
// Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
// They both have an importance value of 3.
// Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.

// Example 2:

// Input: employees = [[1,2,[5]],[5,-3,[]]], id = 5
// Output: -3
// Explanation: Employee 5 has an importance value of -3 and has no direct subordinates.
// Thus, the total importance value of employee 5 is -3.

 

// Constraints:

//     1 <= employees.length <= 2000
//     1 <= employees[i].id <= 2000
//     All employees[i].id are unique.
//     -100 <= employees[i].importance <= 100
//     One employee has at most one direct leader and may have several subordinates.
//     The IDs in employees[i].subordinates are valid IDs.


/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    Employee* getEmployee(int id, vector<Employee*> emps){
        for(auto em : emps){
            if(id == em->id) 
                return em;
        }
        return nullptr;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        unordered_map<int, int> visited;

        queue<Employee*>q;
        q.push(getEmployee(id, employees));

        while(!q.empty()){
            Employee *e = q.front();
            q.pop();

            visited[e->id] = id;

            ans += e->importance;
            for(int i : e->subordinates){
                if(visited.find(i) == visited.end()){
                    Employee *emp = getEmployee(i, employees);
                    if(emp){
                        q.push(emp);
                    }
                }
            }
        }
        
        return ans;
    }
};
































