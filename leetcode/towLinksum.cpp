/*************************************************************************
	> File Name: towLinksum.cpp
	> Author: Zisheng Zou
	> Mail: zzshneuq@163.com
	> Created Time: 2018年05月23日 15:51:23
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;
/**
 * Definition for singly-linked list.
 */

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *result = new ListNode(0); 
        ListNode * p_left = l1 ;
        ListNode * p_right = l2;
        unsigned int left=0;
        unsigned int right=0; 
        }
        ListNode *nu = new ListNode(0) ;
        while(p_left!=nu || p_right!=nu ){
            
            left = left*10 + p_left->val ;
            right = right*10 + p_right->val;
            if(p_left->next)
                p_left = p_left->next ;
            else
                p_left = nu ;
            if(p_right->next)
                p_right = p_right->next ;
            else
                p_right = nu ;
        }
        
        int result_sum = left + right ;
        
        result->val = result_sum%10;
        result_sum = result_sum /10 ;
        
        vector<ListNode* > memoryAssign ;
        while(result_sum){
            ListNode* item = new ListNode(result_sum % 10);
            memoryAssign.push_back(item) ;
            result_sum = result_sum /10 ;
        }
       
        if (memoryAssign.empty())
            return result ;
        int index= 0 ;
        result->next = memoryAssign[index] ;
        
        while(index<memoryAssign.size()-1){
            memoryAssign[index]->next = memoryAssign[++index];
        }
       
        return result ;
    }
};

int main(){

    vector<ListNode*> right(3) ;
    vector<ListNode*> left(3) ;
    ListNode * right_link = new ListNode(0);
    ListNode * left_link = new ListNode(1);

    for(int i=0;i<3;++i){
        right[i] = new ListNode(i+2);
        left[i] = new ListNode(i+1);
    }


//        right_link->next = right[0];
//        left_link->next = left[0];
//        right[0]->next = right[1];
//        left[0]->next = left[1];
//        right[1]->next = right[2];
//        left[1]->next = left[2];
//  
    Solution solv ;

    ListNode* result_out = solv.addTwoNumbers(right_link,left_link);
    return 0 ;
}
