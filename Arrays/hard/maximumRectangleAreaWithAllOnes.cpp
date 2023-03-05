#include<bits/stdc++.h>
 using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size(), ans = 0;
    stack<int> st;

    for(int i = 0; i <= n; i++){
        while(!st.empty() && (i == n || heights[i] <= heights[st.top()])){
            int ht = heights[st.top()];
            st.pop();
            
            int w;
            if(st.empty()) w = i;
            else w = abs(st.top() - i) - 1;

            ans = max(ans, w * ht);
        }
        st.push(i);
    }

  return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
  int ans = 0;
  int n = matrix.size(), m = matrix[0].size();

  vector<int> heights(m, 0);
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
          if(matrix[i][j] == '1') heights[j]++;
          else heights[j] = 0;
      }
      ans = max(ans, largestRectangleArea(heights));
  }  

  return ans;
}

 
int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<char>> matrix(n, vector<char>(m, '0'));
  for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++)
          cin >> matrix[i][j];
  }

  cout<<maximalRectangle(matrix)<<"\n";
  return 0;
} 