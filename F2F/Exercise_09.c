#include <stdio.h>
#include <stdlib.h>

// The time complexity of the 'scanf' function in the 'main' function is O(1).
// The time complexity of the 'printf' function in the 'main' function is also O(1).
// The time complexity of the 'display' function is O(n).

// The overall time complexity of the program is the sum of the time complexities of the
// 'scanf', 'printf', and 'display' functions, which is O(1) + O(1) + O(n) = O(n).

// Therefore, the time complexity of the entire program is O(n), where n is the value entered by the user

int main() // time complexity is constant, O(1).
{
    int num; // time complexity is constant, O(1).

    printf("Enter the number of terms: "); // time complexity is constant, O(1).
    scanf("%d", &num);                     // time complexity of this line is also constant, O(1).

    printf("1 to %d:\n", num); // time complexity is constant, O(1).
    display(num);              // time complexity of this line is constant, O(1).

    return 0;
}

void display(int num) // time complexity of the 'display' function is O(n).
{
    if (num)              // O(1)
        display(num - 1); // O(n)
    else                  // O(1)
        return;

    printf("%d ", num); // O(1)
}
