#ifndef STACK_H
#define STACK_H
#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
// private inheritance since we do not want stack class to see 
// all the member functions of vector class.
class Stack : private std::vector<T>
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

template <typename T>
   Stack<T>::Stack(): std::vector<T>()
      {
      }

template <typename T>
   Stack<T>::~Stack()
      {
      }


template <typename T>
   bool Stack<T>::empty() const
   {
      return std::vector<T>::empty();
   }

template <typename T>
   size_t Stack<T>::size() const
   {
      return std::vector<T>::size();
   }

template <typename T>
   void Stack<T>::push(const T& item)
   {
      std::vector<T>::insert(this->begin(), item);
   }

template <typename T>
   void Stack<T>::pop(){
   if(Stack<T>::empty() == 0){
      throw std::underflow_error("stack is empty");
   }
   else{
      std::vector<T>::erase(this->begin());
   }
}

template <typename T>
   T const & Stack<T>::top() const{
   if(Stack<T>::empty() == 0){
      throw std::underflow_error("stack is empty");
   }
   else{
      return std::vector<T>::front();
   }
}

#endif