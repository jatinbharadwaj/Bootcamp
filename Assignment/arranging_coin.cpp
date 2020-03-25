class Solution {
public:
    int arrangeCoins(int n) {
        
        if(n==1 || n==2)
            return 1;
       int s=0,e=n;
           
    while(s<e){
        
        int m=(s+e)/2;
        long long i=((pow(m,2)+m)/2);
        long long j=((pow(m-1,2)+m-1)/2);
        long long k=((pow(m+1,2)+m+1)/2);
        
        cout<<m<<' '<<i<<' '<<j<<' '<<k<<endl;
        if(i==n)
            return m;
        
        if(k==n)
            return m+1;
        
        if(j<=n && i>n)
            return m-1;
        
        if(i<=n && k>n)
            return m;
        
        if(j>n)
            e=m-1;
        else
            s=m+1;
    }
        return 0;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().arrangeCoins(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
