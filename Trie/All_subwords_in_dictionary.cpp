#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

static const int ALPHABET_SIZE = 26;


template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    for(const auto& element: v)
    {
        os << element <<" ";
    }
    return os;
}

struct TrieNode
{
	bool is_terminal;
	std::vector<std::shared_ptr<TrieNode>> children{ALPHABET_SIZE};
};


std::shared_ptr<TrieNode> GetNode()
{
	std::shared_ptr<TrieNode> pNode = std::make_shared<TrieNode>();
	pNode->is_terminal = false;

	for(int i = 0; i < ALPHABET_SIZE ; ++i)
	{
		pNode->children[i] = nullptr;
	}
	return pNode;
}

void Insert(std::shared_ptr<TrieNode> root, const std::string& key)
{
	int index;
	std::shared_ptr<TrieNode> pCrawl = std::move(root);
	for(int i = 0; i < key.size(); ++i)
	{
		index = key[i] - 'a';
		if(!pCrawl->children[index])
		{
			pCrawl->children[index] = GetNode();
		}
		pCrawl = pCrawl->children[index];

	}
	pCrawl->is_terminal = true;
}

bool Search(std::shared_ptr<TrieNode> root, const std::string& key)
{
	int index;
	std::shared_ptr<TrieNode> pCrawl = std::move(root);
	for(int i = 0; i < key.size(); ++i)
	{
		index = key[i] - 'a';
		if(!pCrawl->children[index])
		{
			return false;
		}
		pCrawl = pCrawl->children[index];
	}
	return (pCrawl->is_terminal == true && pCrawl != nullptr);
}

std::vector<std::string> WordBreakAll(std::shared_ptr<TrieNode> root, std::string key)
{
    int index;
    bool logic = false;
    std::shared_ptr<TrieNode> pCrawl = root;
    std::vector<std::string> result;
    std::string word, prefix;
    for(int i = 0; i < key.size(); ++ i)
    {
        index = key[i] - 'a';
        
        word.push_back(key[i]);
        prefix.push_back(key[i]);
        if(pCrawl->children[index]->is_terminal && Search(root,prefix) && logic)
        {
            result.push_back(prefix);
            prefix.clear();
            
        }
        if(pCrawl->children[index]->is_terminal && Search(root,word))
        {
            result.push_back(word);
            if(!logic){
                prefix.clear();
                logic = true;
            }
            
        }
        pCrawl = pCrawl->children[index];
    }
    return result;
    
}


int main()
{
    std::shared_ptr<TrieNode> tr = std::make_shared<TrieNode>();
    Insert(tr,"ice");
    Insert(tr, "cream");
    Insert(tr, "icecream");
    std::cout << Search(tr,"ice") << std::endl;
    std::cout << Search(tr,"cream") << std::endl;
    std::cout << Search(tr, "icecream") << std::endl;
    std::cout << WordBreakAll(tr, "icecream") << std::endl;
    return 0;
}
