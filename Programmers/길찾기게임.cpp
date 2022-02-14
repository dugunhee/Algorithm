#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdlib.h>
using namespace std;
typedef struct Node{
    int index;
    int x;
    int y;
    struct Node* left;
    struct Node* right;
}Node;
vector<Node> vec;
vector<int> ans0,ans1;
bool cmp(Node a, Node b)
{
    if(a.y == b.y)return a.x<b.x;
    return a.y > b.y;
}
void make_tree(Node* root, Node* child)
{
    if(root->x > child->x){
        if(root->left == NULL){
            root->left = child;
            return;
        }
        make_tree(root->left,child);
    }
    else{
        if(root->right == NULL){
            root->right = child;
            return;
        }
        make_tree(root->right,child);
    }
}
void preorder(Node* root)
{
    if(root == NULL)return;
    ans0.push_back(root->index);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root)
{
    if(root == NULL)return;
    postorder(root->left);
    postorder(root->right);
    ans1.push_back(root->index);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int i,j;
    for(i=1;i<=nodeinfo.size();i++)
    {
        vec.push_back({i,nodeinfo[i-1][0],nodeinfo[i-1][1],NULL,NULL});
    }
    sort(vec.begin(),vec.end(),cmp);
    Node* head = NULL;
    head = &vec[0];
    for(i=1;i<vec.size();i++)
    {
        make_tree(head,&vec[i]);
    }
    preorder(head);
    postorder(head);
    answer.push_back(ans0);
    answer.push_back(ans1);
    return answer;
}