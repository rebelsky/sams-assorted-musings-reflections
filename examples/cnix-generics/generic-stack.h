/**
 * generic-stack.h
 *   Declarations for a simple generic implementation of stacks.
 *
 * <Insert MIT license>
 */

#ifdef TYPE

// +--------+--------------------------------------------------------
// | Macros |
// +--------+

/**
 * By default, we do not rename procedures and structs.
 */
#ifndef TYPED
#define TYPED(THING) THING
#endif

// +-------+---------------------------------------------------------
// | Types |
// +-------+

typedef struct TYPED(Stack) TYPED(Stack);

// +------------+----------------------------------------------------
// | Procedures |
// +------------+

/**
 * Create a new stack.
 */
void TYPED(stack_new) (void);

/**
 * Free the space allocated to a stack.
 */
void TYPED(stack_free) (TYPED(Stack) *stack);

/**
 * Determine the number of elements in the stack.
 */
int TYPED(stack_size) (TYPED(Stack) *stack);

/**
 * Look at the top element of the stack.  Requires that the
 * stack have at least one element.
 */
TYPE TYPED(stack_top) (TYPED(Stack) *stack);

/**
 * Remove and return the top element of the stack.  Requires that
 * the stack have at least one element.
 */
TYPE TYPED(stack_pop) (TYPED(Stack) *stack);

/**
 * Add an element to the stack.
 */
void TYPED(stack_push) (TYPED(Stack) *stack, TYPE val);

#endif // TYPE

