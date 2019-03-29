#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Graph {
private:
// TODO: mutable, volatile and extern. Pure virtual with NULL and constructor, class hirachies, concrete classes and abstract(interfaces).
// TODO: A tour of C++, dynamic_cast<> as type check, never use reinterpt_cast<>, argument dependent lookup, virtual memory address.
  list<T>* verticies;
  /* member variable(a.k.a. charecteristic):
  ** usually prefixed with m that stands for member.
  */
  size_t mNumV;
public:
  /* Default constructor:
  ** An initial size is important for performance, thus this should never get called.
  ** Can be made private, but it's less cleaner as it can be called from within.
  ** Or it can just be deleted.
  */
  explicit Graph() = delete;
  /* Main Constructor:
  ** Making it explicit, because it should be by default, as it saves us from hard to spot errors.
  ** If there is void foo(Graph) then calling foo({5}) will create Graph using this constructor.
  */
  explicit Graph(size_t initNumV): mNumV(initNumV), verticies(new list<T>[initNumV]) {}
  /* Swap function:
  ** We can't use std::swap, because it uses the copy-constructor and copy-assignment operator within its implementation.
  ** We'd ultimately end up defining the copy-assignment in terms of itself.
  ** Bootstraping?? Endless loop??
  ** This function has to swap two objects member by member.
  */
  friend void swap(Graph<T>& first, Graph<T>& second) {
      using std::swap;
      swap(first.verticies, second.verticies);
      swap(first.numV, second.numV);
  }
  /* Copy constructor:
  ** Constructors can only used for initialization.
  ** If you manage resources or locks you'll have to use *The Rule of 5(4??)*
  ** By default the compiler will implement them implicitly,
  ** but that poses a problem if there are pointers otherwise known as resources.
  ** Copied pointers point to the same object as the original; so, changing one's data changes the other's.
  ** There is no guarntee the members will be initialized in order using the member initialization list.
  ** We pass by reference here and use const to make te comiler enforce its constness.
  ** This creates a deep copy.
  */
  explicit Graph(const Graph& copy): mNumV(copy.mNumV),  verticies(new list<T>[copy.mNumV]{*(copy.verticies)}){
    // copy(copy.begin(), copy.end(), begin());
  }
  /* Move constructor:
  ** The parameter(arguemnt if it's passed) is an *rvalue reference*(a temporary that does not
  ** persist beyond the expression that defines it such as a intermediate function
  ** result which is never stored in a variable.), as it will eventually be cleaned.
  ** rvalues are usually produced from plus operators and such.
  ** Why don't we just "steal" the resources making the rvalue's resource nullptr to preserve it as we get out of the
  ** function's scope(smart pointers??) as it will get deleted from the stack.
  ** We pass rvalues reference here as the copy is already created for us.
  ** We can also move from lvalues using std::move, it basically acts as casting functions and tells the compiler:
  ** "Dear compiler, I no longer have a use for foo, do whatever the hell you want with it".
  ** Moving an object doesn't necessarily make it a prvaule(pure rvalue), as it is still owning data(until a move
  ** constructor is called anyways). It instead makes it an xvalue(expiring value).
  **          expressions
  **            /     \
  **           /       \
  **          /         \
  **      glvalues   rvalues
  **        /  \       /  \
  **       /    \     /    \
  **      /      \   /      \
  **  lvalues   xvalues   prvalues
  */
  explicit Graph(Graph&& copy): mNumV(copy.mNumV), verticies(copy.verticies) {
    copy.verticies = nullptr;
  }
  /* Copy and swap idiom:
  ** We have to create a copy, because we don't wan to change any of the two objects.
  ** So, why not let the compiler create one for us using the copy-constructor.
  ** Generally, if you have to make a copy of an object, let the compiler do it in the parameter list(don't pass by const reference).
  ** That way, we will abide by *DRY(Don't Repeate Yourself)* and have a *strong exception guarantee* as the function will never execute
  ** if allocating space to the copy failed; thus, *this object will never be altered nor will the *invariant*.
  ** Then we swap this object with the copy using swap which throws *noexcept*.
  ** Upon leaving the scope the copy is destroyed from the stack, taking with it the old data as the pointers have been swapped.
  */
  Graph& operator=(Graph<T> copy) {
    swap(*this, copy);
    return *this;
  }
  /* 
  ** Used for iterating over verticies, like range for loops(for(const auto& vertex: graph1))
  ** Can be used for std::copy and what not.
  ** This is a *method(member function)* not a free function; as, this function is passed *this* as a parameter
  ** implicitly unlike static methods which aren't free function either(They can be though of as scoped functions).
  ** static outside a class has another meaning, which is: this function
  */
  const list<T>* begin() const {
    return verticies;
  }
  /*
  ** The const quantifier after the function tells the compiler to enforce *this*'s constness. The compiler doesn't allow any
  ** member variable to be changed. foo(const Graph* this) ; this is implicitly passed.
  ** The const before does the same for the reurned value.
  ** The returned const can be used in functions the doesn't promise constness using const_cast<>, which doesn't change the value of const(copy??).
  */
  const list<T>* end() const {
    return verticies + mNumV;
  }
  // Access operator
  list<T>& operator[](size_t index) {
    return verticies[index];
  }/*Functor:
  ** Used in templates(I guess).
  **
  **
  **
  */
  list<T>& operator()(size_t vertex) {
    return verticies[index];
  }
  /* Destructor:
  ** Used for deleting resouces allocated on the free store(dynamic memory, heap) using new.
  ** Helps avoiding memory leaks, where the resources' pointer gets cleaned before the resource is deleted.
  ** We can't delete the resource without knowing where it is in the memory.
  */
  ~Graph() {
    delete[] verticies;
  }
};

int main() {
  // Do something with the Graph once done.
  return 0;
}