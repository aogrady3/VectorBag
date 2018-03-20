#include "VectorBag.h"
#include <cstddef>

template<class ItemType>
VectorBag<ItemType>::VectorBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int VectorBag<ItemType>::getCurrentSize() const
{
   return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool VectorBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool VectorBag<ItemType>::add(const ItemType& newEntry)
{
   bool hasRoomToAdd = (itemCount < maxItems);
   if (hasRoomToAdd)
      {
         items[itemCount] = newEntry;
         itemCount++;
      }  // end if
    
   return hasRoomToAdd;
}  // end add

 
template<class ItemType>
bool VectorBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
   bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
   if (canRemoveItem)
      {
         itemCount--;
         items[locatedIndex] = items[itemCount];
      }  // end if
    
   return canRemoveItem;
}  // end remove


template<class ItemType>
void VectorBag<ItemType>::clear()
{
   itemCount = 0;
}  // end clear

template<class ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
      {
         if (items[curIndex] == anEntry)
            {
               frequency++;
            }  // end if
      
         curIndex++;          // Increment to next entry
      }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getIndexOf(anEntry) > -1;
}  // end contains

template<class ItemType>
vector<ItemType> VectorBag<ItemType>::toVector() const
{
   vector<ItemType> bagContents;
   for (int i = 0; i < itemCount; i++)
      bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int VectorBag<ItemType>::getIndexOf(const ItemType& target) const
{
   bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
      {
         if (items[searchIndex] == target)
            {
               found = true;
               result = searchIndex;
            } 
         else
            {
               searchIndex++;
            }  // end if
      }  // end while
   
   return result;
}  // end getIndexOf

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator+(VectorBag<ItemType> anotherBag)
{
  VectorBag<ItemType> newBag;
  
    //use all elements from both sets
  for (int i = 0; i < itemCount; i++) {
        newBag.add(items[i]);
    }

  for (int j = 0; j < anotherBag.itemCount; j++) {
        newBag.add(anotherBag.items[j]);
    }

    return newBag; 
}

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator*(VectorBag<ItemType> anotherBag)
{
    //find elements used in both sets 
  VectorBag<ItemType> newBag;
  VectorBag<ItemType> firstBag;
       for (int i = 0; i <itemCount; i++) 
	   firstBag.add(items[i]);
    
     VectorBag<ItemType> secondBag;
    for (int j = 0; j < anotherBag.itemCount; j++) 
	secondBag.add(anotherBag.items[j]);

    for (int x = 0; x < itemCount; x++) {
	
    for (int i = 0; i < secondBag.itemCount; i++) {
        for (int j = 0; j < firstBag.itemCount; j++) {
            if (secondBag.items[i] == firstBag.items[j]) {
                newBag.add(firstBag.items[j]);
                firstBag.remove(firstBag.items[j]);
		secondBag.remove(secondBag.items[i]);
            }
        }
    }
    }
    return newBag;
}

template<class ItemType>
VectorBag<ItemType> VectorBag<ItemType>::operator-(VectorBag<ItemType> anotherBag)
{
    // create new bad with 1st bag items 
    VectorBag<ItemType> firstBag;
    for (int x = 0; x < itemCount; x++)
	firstBag.add(items[x]);
    
    //check if items in set1 exists in set2
    for ( int i = 0; i <= firstBag.itemCount; i++)
	for (int j =0; j <= anotherBag.itemCount; j++) {
	    if (firstBag.items[i] == anotherBag.items[j]) {
		firstBag.remove(firstBag.items[i]);
		anotherBag.remove(anotherBag.items[j]);
        }
    }
    return firstBag;
}
