/* File: char_stack.h

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop();
    char top();
    bool empty();
    int size();

  private:
    int top_index;
    static const int capacity = 10;
    char A[capacity];
    // fill this in.
};
