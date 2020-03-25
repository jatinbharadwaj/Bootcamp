class Solution {
       int pivot(vector<int> &a,int n)
       {
        
           int s = 0;
           int e = n-1;
           
           if(a[s]<a[e])
               return s;
            
          
           while(s<e)
           {
               int m=s+(e-s)/2;
            
               
                if(a[m]>a[m+1])
                {
                    return m+1;
                }
               
                if(a[m]<a[m-1])
                {   
                    return m;
                }
               
                if(a[m]>a[0])
                    s=m+1;
               
                else
                    e=m-1;
           }
           return 0;
        }
    
    public:
        int findMin(vector<int>& nums)
        {
            int j=nums.size();
            
            if(j==0)
                return 0;
            if(j==1)
                return nums[0];
            if(j==2)
                return nums[0]<nums[1]?nums[0]:nums[1];
            
            int k=pivot(nums,nums.size());
            return nums[k];        
        }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().findMin(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
