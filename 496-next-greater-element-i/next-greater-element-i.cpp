class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> nge(n2,-1);
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int x:nums1){
            for(int j=0;j<n2;j++){
                if(nums2[j]==x){
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;
    }
};