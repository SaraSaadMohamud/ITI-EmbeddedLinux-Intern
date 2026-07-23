/**
 * @file stack.hh
 * @brief Declaration of the Stack class.
 *
 * This file defines the Stack class, which implements a dynamic
 * stack data structure using a dynamically allocated array.
 *
 * Features:
 * - Push and pop operations.
 * - Deep copy support through the copy constructor and assignment operator.
 * - Automatic memory management using the Rule of Three.
 * - Runtime stack size modification.
 * - Object counting using a static data member.
 * @author Sara Saad Mahmoud
 * @date July 21, 2026
 * @version 1.0
 */

#ifndef _STACK_HH_
#define _STACK_HH_

/**
 * @class Stack
 * @brief Implements a dynamic stack using a heap-allocated array.
 *
 * The Stack class provides standard stack operations (LIFO),
 * supports deep copying, and automatically manages dynamic memory.
*/
class Stack
{
    public:
        /**
            * @brief Default constructor.
            *
            * Creates a stack with a default capacity of 10 elements.
        */
        Stack();

        /**
            * @brief Parameterized constructor.
            *
            * Creates a stack with the specified capacity.
            *
            * @param size Maximum number of elements the stack can hold.
        */
        Stack(const unsigned int &size);

        /**
            * @brief Copy constructor.
            *
            * Creates a deep copy of another Stack object.
            *
            * @param obj Stack object to copy.
        */
        Stack(const Stack &obj);

        /**
            * @brief Destructor.
            *
            * Releases the dynamically allocated memory.
        */
        ~Stack();

        /**
            * @brief Removes and returns the top element.
            *
            * @return The top element of the stack.
            * @retval -1 If the stack is empty.
        */
        int popFromStack();

        /**
            * @brief Pushes a new element onto the stack.
            *
            * @param value Value to be inserted.
        */
        void pushToStack(int value);

        /**
            * @brief Prints all stack elements.
            *
            * Displays the stack contents from bottom to top.
        */
        void printStack() const;

        /**
            * @brief Gets the stack capacity.
            *
            * @return Maximum stack size.
        */
        unsigned int getStackSize() const;

           /**
                * @brief Gets the starting address of the stack array.
                *
                * @return Pointer to the first stack element.
           */
        const int* getStackAddress() const;

        /**
            * @brief Gets the current top index.
            *
            * @return Index of the top element.
            * @retval -1 If the stack is empty.
        */
        int getStackTos() const;

        /**
            * @brief Changes the stack capacity.
            *
            * Existing elements are discarded and a new stack
            * with the specified capacity is allocated.
            *
            * @param size New stack capacity.
        */
        void setStackSize(const unsigned int &size);

        /**
            * @brief Copy assignment operator.
            *
            * Performs a deep copy assignment.
            *
            * @param obj Stack object to copy.
            * @return Reference to the assigned object.
        */
        Stack& operator=(const Stack&obj);

        /**
           * @brief Number of currently existing Stack objects.
        */
        static int stack_cout;

        /**
            * @brief Returns the number of existing Stack objects.
            *
            * @return Current object count.
        */
        static int getStackCount();

    private:
        /**
            * @brief Maximum stack capacity.
        */
        unsigned int stack_size_;

        /**
            * @brief Pointer to the dynamically allocated stack array.
        */
        int *stk_;

        /**
            * @brief Top of Stack index.
            *
            * A value of -1 indicates that the stack is empty.
        */
        int Tos_;
};


#endif /* _STACK_HH_ */