// Ni.cpp

// Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before 
// all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

// Example		  p->S->
	// Input: 8->12->10->5->4->1->7->6->17->15-NULL
// Output: 8->12->10->4->6->17->15->5->1->7->NULL
		    8->12->17
// 			

// int data;
// Node *next;


void SortedNode(Node *head){
   Node* end= *head, *front = NULL , *current = *head;

   // Move to pointer to the end of the NOde
   while(end ->next != NULL){
   		end =end->next;
   } 

   Node *Nend=end;

   // Till First even
   while(current->data %2 != 0 && current!= end){

   		Nend->next = current;
   		current = current->next;
   		Nend->next->next =NULL;
   		Nend = Nend->next;
   }

   // Appending if Even is encountered
   if(current->data%2==0){
   	 *head = current;

   	 // Node even
   	 while(current!=end){
   	 	if((current->data%2==0)){

   	 		front = current;
   	 		current = current->next;
   	 	}
   	 	else{

   	 		front->next = current->next;
   	 		current->next = NULL;
   	 		Nend->next = current;

   	 		Nend =current;

   	 		current = front->next;
   	 	}
   	 }
   }
   else 
   	front = current;
   if(Nend != end && (end->data) %2 != 0){
   	front->next =end->next;
   	end->next = NULL;
   	Nend->next =end;
   }

   return;
}	


    
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// You are given a target value to search. If found in the array return its index, otherwise return -1.
// You may assume no duplicate exists in the array.
// Your algorithm's runtime complexity must be in the order of O(log n).
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4




int BSearch (vector<int> &v, int target,int l, int r,bool firsthalf){

	if(firsthalf){

			while(l<=r){
		int m = (l+r)/2;

		if(v[m] == target){
			return m;
		}

		if(v[m]<target){
			l = m+1;
		}

		else{
			r=m-1;
		}
	}

	return -1;

	}






}



int solve(vector<int> v,int target){

	int n = v.size();
	int l = 0, r =n-1;
	int pivot = 0;

	while(l<=r){
		int mid = (l+r)/2;

		if(v[mid] >v[mid-1] && v[mid] > v[mid+1]){
			pivot = mid;
			break;
		}

		else if(v[mid]<v[mid+1]){
			l = mid;
		}

		else{
			r = mid;
		}
	}

	int idx =  BSearch(v,target,0,pivot,true);
}