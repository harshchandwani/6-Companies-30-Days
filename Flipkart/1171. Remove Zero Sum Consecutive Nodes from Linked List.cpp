class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        ListNode *dummynode=new ListNode(0),*curr=dummynode;
        dummynode->next=head;
        map<int,ListNode*> mp;
        int sum=0;
        while(curr)
        {
            sum+=curr->val;
            if(mp.count(sum))
            {
                curr=mp[sum]->next;
                int p=sum+curr->val;
                while(p!=sum)
                {
                    mp.erase(p);
                    curr=curr->next;
                    p+=curr->val;
                }
                mp[sum]->next=curr->next;
            }
            else
            {
                mp[sum]=curr;
            }
            curr=curr->next;
        }
        return dummynode->next;
    }
};
