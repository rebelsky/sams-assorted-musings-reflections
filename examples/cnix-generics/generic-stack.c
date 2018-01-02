/**
 * generic-stack.c
 *   A simple generic implementation of stacks.
 *
 * <Insert MIT license>
 */

// +---------+-------------------------------------------------------
// | Headers |
// +---------+

#include "stack.h"
#include <stdlib.h>

// +-------+---------------------------------------------------------
// | Types |
// +-------+

/**
 * The nodes in our stack.
 */
struct TYPED(StackNode)
  {
    TYPE val;                    // The value at the top of the stack
    struct TYPED(StackNode) *next;     // The rest of the values in the stack.
  };

/**
 * The stack itself.
 */
struct TYPED(Stack)
  {
    int size;                   // How many elements are in the stack?
    struct TYPED(StackNode) *top;      // What's at the top of the stack?
  };

// +------------+----------------------------------------------------
// | Procedures |
// +------------+

void 
TYPED(stack_new) (void)
{
  struct TYPED(Stack) *new_stack = (struct TYPED(Stack) *) malloc (sizeof (struct TYPED(Stack)));
  new_stack->size = 0;
  new_stack->top = NULL;
} // stack_new


void 
TYPED(stack_free) (TYPED(Stack) *stack)
{
  // Free all the nodes in the stack
  struct TYPED(StackNode) *tmp;
  while ((tmp = stack->top) != NULL)
    {
      stack->top = tmp->next;
      free (tmp);
    } // while
  // Free the stack itself
  free (stack);
} // stack_free

int
TYPED(stack_size) (TYPED(Stack) *stack)
{ 
  return stack->size;
} // stack_size
 
TYPE 
TYPED(stack_top) (TYPED(Stack) *stack)
{
  return stack->top->val;
} // stack_top

TYPE 
TYPED(stack_pop) (TYPED(Stack) *stack)
{
  // Remember the top node and its value
  struct TYPED(StackNode) *tmp = stack->top;
  TYPE top = tmp->val;
  // Drop that node
  stack->top = stack->top->next;
  free (tmp);
  --stack->size;
  // And return the saved value
  return top;
} // stack_pop

void 
TYPED(stack_push) (TYPED(Stack) *stack, TYPE val)
{
  struct TYPED(StackNode) *new_top = 
    (struct TYPED(StackNode) *) malloc (sizeof (struct TYPED(StackNode)));
  new_top->val = val;
  new_top->next = stack->top->next;
  stack->top = new_top;
} // stack_push


