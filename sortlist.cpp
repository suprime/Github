#include <iostream>
#include <assert.h>
using namespace std;
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 class Solution{
 public:
	 ListNode* sortList(ListNode* head){
	 return divide(head);
	 }


	 ListNode* divide(ListNode* head){
		 if(head == NULL || head->next == NULL){
			return head;
		 }
		 ListNode *middle=head,*tail=head,*pre;
		 while(tail !=NULL && tail->next != NULL){
			 pre=middle;
			 middle=middle->next ;
			 tail=tail->next->next; 
		 }
		 pre->next = NULL;
		 ListNode *first=divide(head);
		 ListNode *second=divide(middle);
		 return merge(first,second);
	 }

	 ListNode *merge(ListNode *first,ListNode *second){
		ListNode *head,*list;
		if(first != NULL && second != NULL){
			if(first->val < second->val ){
			 head = first;
			 first = first->next ;
			}else{
			 head = second;
			 second = second->next ;
			}
			list=head;
		 }

		while(first != NULL && second != NULL){
			if(first->val < second->val ){
			 list->next = first;
			 first = first->next ;
			}else{
			 list->next = second ;
			 second = second->next ;
			}
			list=list->next ;
		}

		if(first == NULL){
		    list->next = second;
		}else{
			list->next =first;
		}
		return head;
	 }
 };


 int main(){
 ListNode *head=new ListNode(1),*tmp=head;
 head->next=new ListNode(8);
 head->next->next=new ListNode(5);
 Solution s;
 s.sortList(head);
 while(head != NULL) {
	cout << head->val << "  " << endl;
	head=head->next ;
 }

 return 0;
} 
