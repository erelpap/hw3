#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());
	

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heap; 
  int m_ary;
	PComparator comparator;

};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
	// in case the values are not default we assign it here
	m_ary = m;
	comparator = c;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){};

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions tHeap<T,PComparator>::o handle the case of trying
  // to access the top element of an empty heap

  if(heap.empty()){
		throw std::out_of_range("heap is empty");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else{
    return heap[0];
	}
}
// We will start pop() for you to handle the case of 
// calling top on an empty heap

template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(heap.empty()){
		throw std::out_of_range("heap is empty");
  }

	else{
    // XXXXXXXXXXXX POP XXXXXXXXXXXX
		heap[0] = heap[heap.size() - 1];
		heap.pop_back();
		unsigned int parentIndex = 0;
		if(heap.size() == 0){
			return;
		}

		unsigned int BestChildIndex = parentIndex * m_ary + 1;
		bool height2 = false;
		// for loop to find the best child of siblings at height 2
		for(int i = 2; i <= m_ary; i++){
			unsigned int siblingIndex = parentIndex * m_ary + i;
			// if sibling index is out of range search for best child ends
			if(siblingIndex > heap.size() - 1){
				height2 = true;
				break;
			}
			else{
				if(comparator(heap[parentIndex * m_ary + i], heap[BestChildIndex])){
					// if the sibling is better than the best child a new best child is assigned
					BestChildIndex = parentIndex * m_ary + i;
				}
			}
		}
		// if height is 2 just one swap is done and after that the function completes
		if(height2 && comparator(heap[BestChildIndex], heap[parentIndex])){
			T temp = heap[parentIndex];
			heap[parentIndex] = heap[BestChildIndex];
			heap[BestChildIndex] = temp;
			return;
		}

		bool whileBreak = false;

		while(comparator(heap[BestChildIndex], heap[parentIndex])){
			T temp = heap[parentIndex];
			heap[parentIndex] = heap[BestChildIndex];
			heap[BestChildIndex] = temp;

			if(whileBreak){
				break;
		  }

			parentIndex = BestChildIndex;
			BestChildIndex = parentIndex * m_ary + 1;

			if(BestChildIndex > heap.size() - 1){
				break;
			}

			for(int i = 2; i <= m_ary; i++){
				unsigned int siblingIndex = parentIndex * m_ary + i;
				if(siblingIndex > heap.size() - 1){
					// if the heap is ending then the while will stop in the next iteration
					whileBreak = true;
					break;
				}
				else{
					if(comparator(heap[siblingIndex], heap[BestChildIndex])){
						BestChildIndex = siblingIndex;
					}
				}
		  }
	  }
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
 return heap.size(); 
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	heap.push_back(item);

	// comparator(child, parent): if child has a priority over parent -> TRUE
	if (heap.size() == 1){
		return;
		// nothing to do if there is only one item
	}

	unsigned int childIndex =  heap.size() - 1; // last item
	unsigned int parentIndex;

	if((childIndex - 1) / m_ary <= 0){
			parentIndex = 0;
			// to be sure that parent index is not below 0
		}
		else{
			parentIndex = (childIndex - 1) / m_ary;
		}

	while(comparator(heap[childIndex], heap[parentIndex])){
		// while the child has a priority
		T temp = heap[parentIndex];
		heap[parentIndex] = heap[childIndex];
		heap[childIndex] = temp;
		// switch places of child and parent

		childIndex = parentIndex;
		if(childIndex == 0){
			return;
			// if child at the top: done
		}
		if((childIndex - 1) / m_ary <= 0){
			parentIndex = 0;
			// to be sure that parent index is not below 0
		}
		else{
			parentIndex = (childIndex - 1) / m_ary;
		}
  }
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
	return heap.empty();
}






#endif

