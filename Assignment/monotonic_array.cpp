class Solution {
    bool increasing(vector<int> A)
    {
        int i=0,j=A.size();
        while(i<j-1 && A[i]<=A[i+1])
        { 
            if(A[i]>A[i+1])
                return false;
            i++;                                    
        }
        
        if(i==A.size()-1)
            return true;
        else 
            return false;
    }
    bool decreasing(vector<int> A)
    {
        int i=0,j=A.size();

        while(i<j-1 && A[i]>=A[i+1])
        { 
         if(A[i]<A[i+1])
                return false;
            i++;
        }
        
        if(i==A.size()-1)
            return true;
        else 
            return false;
    }
    
public:
    bool isMonotonic(vector<int>& A) 
    {   
        int i=0,j=A.size()-1;
        if(j==0 || j==1 || j==-1)
            return true;
        
        
        while(i<j && A[i]==A[i+1] ){
            if(i==A.size()-1) 
                return true;
            i++;
        }
        
        if(i==A.size()-1) return true;
        
        if(A[i]<A[i+1]) 
        {
            
            bool tmp=increasing(A);
            
            return tmp;
        }
        else
        {
            bool tmp=decreasing(A);
            return tmp;
        }
        return false;
        
    }
};s
