#ifndef WORDTREE_H
#define WORDTREE_H

#include <iostream>
#include <string>

typedef std::string IType;

struct WordNode {
	IType m_data;
	WordNode *m_left;
	WordNode *m_right;
	// You may add additional data members and member functions
	// in WordNode
	int count;
};

class WordTree {
private:
	WordNode *root;
	void copyHelper(WordNode*& change, const WordNode* source);
	void swapWordTree(WordTree& other);
	void create(IType v, int number, WordNode*& addHere);
	int distinctWordsX(WordNode* sub) const;
	int totalWordsX(WordNode* sub) const;
	void addX(IType v, WordNode* cur);
	void streamHelper(std::ostream& output, WordNode* checkMe) const;
	void clear(WordNode* node);
public:
	// default constructor
	WordTree() : root(nullptr) { };

	// copy constructor
	WordTree(const WordTree& rhs);

	// assignment operator
	const WordTree& operator=(const WordTree& rhs);

	// Inserts v into the WordTree
	void add(IType v);

	// Returns the number of distinct words / nodes
	int distinctWords() const;

	// Returns the total number of words inserted, including
	// duplicate values
	int totalWords() const;

	// Prints the LinkedList
	friend std::ostream& operator<<(std::ostream &out, const WordTree& rhs);

	// Destroys all the dynamically allocated memory in the
	// tree
	~WordTree();
};

#endif