#include <iostream>
#include <memory>
#include <string>
#include <vector>

const int alphabet_size = 26;


struct  TrieVertex
{
    bool is_terminal;
    std::vector<std::shared_ptr<TrieVertex>> children{alphabet_size};
};



std::shared_ptr<TrieVertex> GetNode()
{
    std::shared_ptr<TrieVertex> pNode = std::make_shared<TrieVertex>();
    pNode->is_terminal = false;
    
    for(int i = 0; i < alphabet_size;++i)
    {
        pNode->children[i] = nullptr;
    }
    
    return pNode;
}



void insert(std::shared_ptr<TrieVertex> root,const std::string& key)
{
    std::shared_ptr<TrieVertex> pCrawl = root;
    for(int i = 0; i < key.size();++i)
    {
        int index = key[i] - 'a';
        if(!pCrawl->children[index])
        {
            pCrawl->children[index] = GetNode();
            
        }
        pCrawl = pCrawl->children[index];
    }
    pCrawl->is_terminal = true;
}

bool search(std::shared_ptr<TrieVertex> root,const std::string& key)
{
    std::shared_ptr<TrieVertex> pCrawl = root;
    int index = 0;
    for(int i =0; i < key.size();++i)
    {
        index = key[i] - 'a';
        if(pCrawl->children[index] == nullptr)
        {
            return false;
        }
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->is_terminal == true && pCrawl != nullptr);
}


int main()
{
    return 0;
}