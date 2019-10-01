
void math( double (&stack)[4], OPERAND op ) {
  // Perform the operation on the first two in the stack
  switch(op) {
    case PLUS:
      stack[0] = stack[1] + stack[0];
      stack[1] = stack[2];
      stack[2] = stack[3];
      break;
    case MINUS:
      stack[0] = stack[1] - stack[0];
      stack[1] = stack[2];
      stack[2] = stack[3];
      break;
    case TIMES:
      stack[0] = stack[1] * stack[0];
      stack[1] = stack[2];
      stack[2] = stack[3];
      break;
    case DIVIDE:
      stack[0] = stack[1] / stack[0];
      stack[1] = stack[2];
      stack[2] = stack[3];
      break;
  }
  return;
};
