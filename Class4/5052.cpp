#include<iostream>
#include<string>
#include<vector>
#include<string.h>
using namespace std;
int t,n;
struct Trie{
    bool finish;
    bool hasChild;
    Trie* next[10];
    Trie(){
        memset(next,0,sizeof(next));
    }
    ~Trie(){
        for(int i=0;i<10;i++){
            if(next[i]) delete next[i];
        }
    }
    void insert(const char* key){
        if(*key == '\0'){
            finish = true;
            return;
        }
        int curr = *key - '0';
        if(next[curr] == NULL){
            next[curr] = new Trie();
        }
        hasChild = true;
        next[curr]->insert(key+1);
    }
    bool find(const char* key){
        if(*key == '\0'){
            return true;
        }
        int curr = *key - '0';
        if(next[curr] == NULL) return false;
        return next[curr]->find(key+1);
    }
    bool consistent(){
        if(hasChild && finish) return false;
        for(int i=0;i<10;i++){
            if(next[i] && !next[i]->consistent()) return false;
        }
        return true;
    }
};
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        Trie* root = new Trie();
        for(int i=0;i<n;i++){
            char str[11];
            cin>>str;
            root->insert(str);
        }
        if(root->consistent()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

/*#include<iostream>
#include<string>
using namespace std;
struct Trie{
    bool finish;
    bool hasChild;
    Trie* next[10];
};
bool ans = false;
Trie* getNode(){
    Trie* new_node = new Trie();
    new_node->finish = false;
    for(int i=0;i<10;i++){
        new_node->next[i] = 0;
    }
    return new_node;
}
void insert(Trie* root, string key){
    Trie* tmp = root;
    int len = key.length();
    for(int i=0;i<len;i++){
        int curr = key[i] - '0';
        if(!tmp->next[curr]){
            tmp->next[curr] = getNode();
        }
        tmp->hasChild = true;
        tmp = tmp->next[curr];
    }
    tmp->finish = true;
}
bool consistent(Trie* root){
    Trie* tmp = root;
    if(tmp->hasChild && tmp->finish) return false;
    for(int i=0;i<10;i++){
        if(tmp->next[i] && !consistent(tmp->next[i]))return false;
    }
    return true;
}
int main(){
    int t,n;
    cin>>t;
    for (int i = 0; i < t; i++){
        cin>>n;
        // ans = false;
        string tmp;
        Trie *root = getNode();
        for (int j = 0; j < n; j++){
            cin>>tmp;
            insert(root, tmp);
        }
        if (consistent(root)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
*/