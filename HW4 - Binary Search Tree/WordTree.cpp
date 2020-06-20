#include "WordTree.h"
using namespace std;

void WordTree::create(IType v, int number, WordNode*& addHere)
//	***NEEDS TO BE A REFERNCE TO A POINTER BECAUSE PBV WON'T HAVE THE CHANGES BEING 
//		SAVED TO THE ACTUAL POINTERS!!!
{
	addHere = new WordNode;
	addHere->count = number;
	addHere->m_data = v;
	addHere->m_left = nullptr;
	addHere->m_right = nullptr;
}

void WordTree::copyHelper(WordNode*& change, const WordNode* source)
{
	if (source == nullptr)
		return;
	create(source->m_data, source->count, change);
	copyHelper(change->m_left, source->m_left);
	copyHelper(change->m_right, source->m_right);
}
// copy constructor
WordTree::WordTree(const WordTree& rhs)
{
	//specific empty tree case to lessen the load on copyH
	if (rhs.root == nullptr)
		this->root = nullptr;
	else
		copyHelper(this->root, rhs.root);
}

// assignment operator
const WordTree& WordTree::operator=(const WordTree& rhs)
{
	if (this != &rhs)
	{
		WordTree temp(rhs);
		swapWordTree(temp);
	}
	return *this;
}

void WordTree::swapWordTree(WordTree& other)
// Exchange the contents of this tree with the other one.
{
	WordNode* tempPtr = root;
	root = other.root;
	other.root = tempPtr;
	tempPtr = nullptr;
}

void WordTree::addX(IType v, WordNode* cur)
{
	//because of the base-case check, I am guaranteed to have a non-nullptr "cur"
	if (v == cur->m_data)
		cur->count = cur->count + 1;
	else if (v < cur->m_data)
	{
		if (cur->m_left == nullptr)
			create(v, 1, cur->m_left);
		else addX(v, cur->m_left);
	}
	else if (v > cur->m_data)
	{
		if (cur->m_right == nullptr)
			create(v, 1, cur->m_right);
		else addX(v, cur->m_right);
	}
	else
		cerr << "Error: this should never run!" << endl;

}
// Inserts v into the WordTree
void WordTree::add(IType v)
{
	if (root == nullptr)
		//base case where tree is empty
		create(v, 1, root);
	else
		addX(v, root);
}

int WordTree::distinctWordsX(WordNode* sub) const
{
	if (sub == nullptr)
		return 0;
	return (1 + distinctWordsX(sub->m_left) + distinctWordsX(sub->m_right));
}
// Returns the number of distinct words / nodes
int WordTree::distinctWords() const
{
	return distinctWordsX(root);
}

int WordTree::totalWordsX(WordNode* sub) const
{
	if (sub == nullptr)
		return 0;
	return (sub->count + totalWordsX(sub->m_left) + totalWordsX(sub->m_right));
}
// Returns the total number of words inserted, including
// duplicate values
int WordTree::totalWords() const
{
	return totalWordsX(root);
}

void WordTree::streamHelper(ostream& output, WordNode* checkMe) const
{
	if (checkMe == nullptr)
		return;
	streamHelper(output, checkMe->m_left);
	output << checkMe->m_data << " " << checkMe->count << endl;
	streamHelper(output, checkMe->m_right);
	return;
}
// Prints the LinkedList
ostream& operator<<(ostream &out, const WordTree& rhs)
{
	rhs.streamHelper(out, rhs.root);
	return out;
}

void WordTree::clear(WordNode* node)
{
	if (node == nullptr)
		return;
	clear(node->m_left);
	clear(node->m_right);
	delete node;
}
// Destroys all the dynamically allocated memory in the
// tree
WordTree::~WordTree()
//POST-ORDER!!!
{
	clear(root);
}