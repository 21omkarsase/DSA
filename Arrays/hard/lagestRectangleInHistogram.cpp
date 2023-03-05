#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea3(vector<int>& heights) {
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


int largestRectangleArea2(vector<int>& heights) {
   int n = heights.size();
   stack<int> st;
   vector<int> leftSmall(n, 0), rightSmall(n, 0);

   for(int i = 0; i < n; i++){
       while(!st.empty() && heights[st.top()] >= heights[i]){
           st.pop();
       }

       if(st.empty()) leftSmall[i] = 0;
       else leftSmall[i] = st.top() + 1;

       st.push(i);
   }

   while(!st.empty()) st.pop();

   for(int i = n - 1; i >= 0; i--){
       while(!st.empty() && heights[st.top()] >= heights[i]){
           st.pop();
       }

       if(st.empty()) rightSmall[i] = n - 1;
       else rightSmall[i] = st.top() - 1;

       st.push(i);
   }

   int ans = 0;
   for(int i = 0; i < n; i++){
       ans = max(ans, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
   }

   return ans;
}

int lraHelper(vector<int> heights, int h, int i, string side, int n){
    if(i == -1 || i == n) return 0;
   
    if(heights[i] < h) return 0;

    if(side == "both"){
        int right = 0, left = 0;
        if(heights[i] >= h) right = lraHelper(heights, h, i + 1, "right", n);
        if(heights[i] >= h) left = lraHelper(heights, h, i - 1, "left", n);
        return left + right + 1;
    }
    
    int ans = 0;
    if(side == "left"){
        if(heights[i] >= h) ans = lraHelper(heights, h, i - 1, side, n) + 1;
    }else {
        if(heights[i] >= h) ans = lraHelper(heights, h , i + 1, side, n) + 1; 
    }

    return ans;
}

int largestRectangleArea1(vector<int>& heights) {
   int ans = INT_MIN;
   int n = heights.size();
   for(int i = 0; i < n; i++){
       int area = heights[i] * (lraHelper(heights, heights[i], i, "both", n));
       ans = max(ans, area);
   } 

   return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> heights(n, 0);
    for(auto &e : heights) cin >> e;

    cout<<largestRectangleArea1<<"\n";

    cout<<largestRectangleArea2<<"\n";

    cout<<largestRectangleArea3<<"\n";

    return 0;
}