#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot_helper(Node*& head, Node*& smaller, Node*& larger, int pivot){
	if(head == nullptr){ // when we are at the end of the initial ll
	// we make the last nodes point to nullptr's
	  larger = nullptr;
		smaller = nullptr;
	}
	else if(head->val <= pivot){
		// if the value is smaller than the pivot we make the latest smaller node point the current node in the initial ll
		smaller = head;
		// we iterate the head and the smaller ll's since we added a new node to larger
		llpivot_helper(head->next, smaller->next, larger, pivot);
	} 
	else if(head->val > pivot){
		// if the value is larger than the pivot we make the latest larger node point the current node in the initial ll
		larger = head;
		// we iterate the head and the larger ll's since we added a new node to larger
		llpivot_helper(head->next, smaller, larger->next, pivot);
	}
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
	// we use two functions to be able to delete the initial head pointer 
	// after we iterate through the initial ll
	llpivot_helper(head, smaller, larger, pivot);
	head = nullptr;
}


