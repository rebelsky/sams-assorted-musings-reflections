/**
 * stack.c
 *   A simple implementation of stacks.
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
struct StackNode
  {
    int val;                    // The value at the top of the stack
    struct StackNode *next;     // The rest of the values in the stack.
  };

/**
 * The stack itself.
 */
struct Stack
  {
    int size;                   // How many elements are in the stack?
    struct StackNode *top;      // What's at the top of the stack?
  };

// +------------+----------------------------------------------------
// | Procedures |
// +------------+

void 
stack_new (void)
{
  struct Stack *new_stack = (struct Stack *) malloc (sizeof (struct Stack));
  new_stack->size = 0;
  new_stack->top = NULL;
} // stack_new


void 
stack_free (Stack *stack)
{
  // Free all the nodes in the stack
  struct StackNode *tmp;
  while ((tmp = stack->top) != NULL)
    {
      stack->top = tmp->next;
      free (tmp);
    } // while
  // Free the stack itself
  free (stack);
} // stack_free


int 
stack_size (Stack *stack)
{ 
  return stack->size;
} // stack_size
 
int 
stack_top (Stack *stack)
{
  return stack->top->val;
} // stack_top

int 
stack_pop (Stack *stack)
{
  // Remember the top node and its value
  struct StackNode *tmp = stack->top;
  int top = tmp->val;
  // Drop that node
  stack->top = stack->top->next;
  free (tmp);
  --stack->size;
  // And return the saved value
  return top;
} // stack_pop

void 
stack_push (Stack *stack, int val)
{
  struct StackNode *new_top = 
    (struct StackNode *) malloc (sizeof (struct StackNode));
  new_top->val = val;
  new_top->next = stack->top->next;
  stack->top = new_top;
} // stack_push


