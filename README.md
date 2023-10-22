# An interpreter for Monty ByteCodes files.

# 0x19. C - Stacks, Queues - LIFO, FIFO

## TASK 0: `push`, `pall`

*The opcode pushes an element to the stack.*

## TASK 1: `pint`

*The opcode prints the value at the top of the stack, followed by a new line.*

## TASK 2: `pop`

*The opcode removes the top element of the stack.*

## TASK 3: `swap`

*The opcode swaps the top two elements of the stack.*

## TASK 4: `add`

*The opcode adds the top two elements of the stack.*

## TASK 5: `nop`

*The opcode push pushes an element to the stack.*

## TASK 6: `sub`

*The opcode subtracts the top element of the stack from the second top element of the stack*

## TASK 7: `div`

*The opcode divides the second top element of the stack by the top element of the stack*

## TASK 8: `mul`

*The opcode multiplies the second top element of the stack with the top element of the stack.*

## TASK 9: `mod`

*The opcode computes the rest of the division of the second top element of the stack by the top element of the stack.*

## TASK 10: # *comment*

*When the first non-space character of a line is #, treat this line as a comment (don’t do anything).*

## TASK 11: `pchar`

The opcode prints the char at the top of the stack, followed by a new line*

## TASK 12: `pstr`
The opcode pstr prints the string starting at the top of the stack, followed by a new line.

## TASK 13: `rotl`
The opcode rotl rotates the stack to the top.

## TASK 14: `rotr`
The opcode rotr rotates the stack to the bottom.

## TASK 15: `stack` and `queue`
*Stack and queue opcodes.*
- The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.
- The opcode queue sets the format of the data to a queue (FIFO).

## TASK 16 `1000-school.bf`
a Brainf*ck script that prints School, followed by a new line.

## TASK 16 `1001-school.bf`
Add two digits given by the user.
