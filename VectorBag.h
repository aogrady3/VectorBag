#ifndef VECTORBAG_H
#define VECTORBAG_H

#include "BagInterface.h"

template<class ItemType>
class VectorBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 20; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
   int itemCount;                         // Current count of bag items 
   int maxItems;                          // Max capacity of the bag
   
   // Returns either the index of the element in the array items that
   // contains the given target or -1, if the array does not contain 
   // the target.
   int getIndexOf(const ItemType& target) const;   

public:
	VectorBag();
	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
        vector<ItemType> toVector() const;
     VectorBag<ItemType> operator+(VectorBag<ItemType> anotherBag);
     VectorBag<ItemType> operator-(VectorBag<ItemType> anotherBag);
     VectorBag<ItemType> operator*(VectorBag<ItemType> anotherBag);
    
}; // end VectorBag

#include "VectorBag.cpp"
#endif
