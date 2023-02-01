#include <stdio.h>

void add(int *x, int *y, int *sum);
void subtract(int *x, int *y, int *difference);
void multiply(int *x, int *y, int *product);
void divide(int *x, int *y, float *quotient);

int main() 
{
  int x, y;
  int sum, difference;
  int product;
  float quotient;
  char operator;
  
  printf("Enter first number: ");
  scanf("%d", &x);
  printf("Enter second number: ");
  scanf("%d", &y);
  printf("Enter operator (+, -, *, /): ");
  scanf(" %c", &operator);

  switch(operator)
  {
    case '+':
      add(&x, &y, &sum);
      printf("Sum: %d\n", sum);
      break;
    case '-':
      subtract(&x, &y, &difference);
      printf("Difference: %d\n", difference);
      break;
    case '*':
      multiply(&x, &y, &product);
      printf("Product: %d\n", product);
      break;
    case '/':
      divide(&x, &y, &quotient);
      printf("Quotient: %.2f\n", quotient);
      break;
    default:
      printf("Invalid operator.\n");
  }

  return 0;
}

void add(int *x, int *y, int *sum)
{
  *sum = *x + *y;
}

void subtract(int *x, int *y, int *difference)
{
  *difference = *x - *y;
}

void multiply(int *x, int *y, int *product) 
{
  *product = *x * *y;
}

void divide(int *x, int *y, float *quotient) 
{
  *quotient = (float)*x / (float)*y;
}

