#include <stdio.h>
#include <stdlib.h>

#define size 11

int array[size];

void display();
void insert(int data);

int main(){ 
    
    //initialize to -1 as default value
    for (int i = 0; i < size; i++) {
        array[i] = -1;
    }
    //insert {4,6,5,7,10,1,3,13}
    insert(4);
    insert(6);
    insert(5);
    insert(7);
    insert(10);
    insert(1);
    insert(3);
    insert(13);

    display();
    return 0;
}

void insert(int data){
    int i = 0;
    while (i < size){
        int index = (i + data) % size;
        if (array[index] == -1){
            array[index] = data;
            return;
        }
        i++;
    }
    printf("Error: Array is full!\n");
}

void display(){
    int i;
    printf("Index\tData");
    for(i = 0; i < size; i++){
        if(array[i] == -1){
            printf("\n%d\tNULL", i);
        }
        else{
            printf("\n%d\t%d", i, array[i]);
        }
    }
}