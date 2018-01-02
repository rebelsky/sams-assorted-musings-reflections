#ifndef _STACK_H_
#define _STACK_H_

/**
 * stack.h
 *   Declarations for a simple implementation of stacks.
 *
 * <Insert MIT license>
 */

// +-------+---------------------------------------------------------
// | Types |
// +-------+

typedef struct Stack Stack;

// +------------+----------------------------------------------------
// | Procedures |
// +------------+

/**
 * Create a new stack.
 */
void stack_new (void);

/**
 * Free the space allocated to a stack.
 */
void stack_free (Stack *stack);

/**
 * Determine the number of elements in the stack.
 */
int stack_size (Stack *stack);

/**
 * Look at the top element of the stack.  Requires that the
 * stack have at least one element.
 */
int stack_top (Stack *stack);

/**
 * Remove and return the top element of the stack.  Requires that
 * the stack have at least one element.
 */
int stack_pop (Stack *stack);

/**
 * Add an element to the stack.
 */
void stack_push (Stack *stack, int val);

#endif // _STACK_H_

