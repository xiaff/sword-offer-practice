/*
    面试题50：树中两个结点的最低公共祖先
    求树中两个结点的最低公共祖先。
*/

struct TreeNode{
    int val;
    vector<TreeNode*> children;
};

class Solution
{
public:
    TreeNode* GetLastCommonParent(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2){
        if(pRoot==NULL || pNode1==NULL || pNode2==NULL)
            return NULL;
        list<TreeNode*> path1;
        GetNodePath(pRoot,pNode1,path1);
     
        list<TreeNode*> path2;
        GetNodePath(pRoot,pNode2,path2);
     
        return GetLastCommonNode(path1,path2);
    }

private:
    bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*> &path){
        if(pRoot==pNode)
            return true;
        path.push_back(pRoot);
     
        vector<TreeNode*>::iterator it=pRoot->children.begin();
        bool found = false;
        while(!found && it!=pRoot->children.end()){
            found=GetNodePath(*it,pNode,path);
            ++it;
        }
     
        if(!found)
            path.pop_back();
     
        return found;
    }
 
    TreeNode* GetLastCommonNode(const list<TreeNode*> &path1,const list<TreeNode*> &path2){
        list<TreeNode*>::const_iterator it1=path1.begin();
        list<TreeNode*>::const_iterator it2=path2.begin();
     
        TreeNode* pLast=NULL;
     
        while(it1!=path1.end() && it2!=path2.end()){
            if(*it1==*it2)
                pLast=*it1;
            it1++;
            it2++;
        }
        return pLast;
    }    
};