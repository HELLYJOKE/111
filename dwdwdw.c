#include <stdio.h>
#include <stdlib.h>




int check_size_array(int size);
int check_index_array(int index);
int check_value_array(int value);
int check_indexdel_array(int inddel, int n);
int* scanf_array(int n);
void print_array(int *a, int n) ;
int individual_task(int ch);
void increase_array(int **a, int *n, int index, int value);
void del_array(int **mass, int *n, int y);
int ab(int chislo);








int main()
{
    int array_size = 0, array_index = 0, array_value = 0, array_indexdel = 0, menu_ind = 0;
    int *array= NULL;

    for (;;){

        printf("\n\nchoose command:\n\n 1-fill array\n 2-add elements in array\n 3-erase elements from array\n 4-print array\n 5-individual assignment\n 6-exit programm\n\n\n");
        printf("enter the command number: ");



        if ((scanf("%d",&menu_ind) != 1) || (menu_ind < 1) || (menu_ind > 6)){
            scanf("%*[^\n]");
            printf("there is no such command in the menu, choose another one\n\n");
        }




        else{
        switch(menu_ind){



            case 1:

                if (array == NULL){
                    printf("\nInput the value of array size: ");
                    array_size = check_size_array(array_size);
                    array = scanf_array(array_size);
                    break;
                }
                else{
                    free(array);
                    printf("\nInput the value of array size: ");
                    array_size = check_size_array(array_size);
                    array = scanf_array(array_size);
                    break;
                }




            case 2:
                if (array == NULL){
                    printf("it seems you forgot to initialize your array, run command 1\n\n");
                    break;
                }
                else{

                    increase_array(&array, &array_size, array_index, array_value);
                    break;
                }





            case 3:
                if (array == NULL){
                    printf("it seems you forgot to initialize your array, run command 1\n\n");
                    break;
                }
                else{
                    printf("Items, that we want to remove: ");
                    array_indexdel = check_indexdel_array(array_indexdel, array_size);
                    del_array(&array, &array_size, array_indexdel);
                    break;
                }





            case 4:
                if (array == NULL){
                    printf("your array is empty\n\n");
                    break;
                }
                else{
                print_array(array, array_size);
                break;
                }




            case 5:
                if (array == NULL){
                    printf("it seems you forgot to initialize your array, run command 1\n\n");
                    break;
                }
                else{
                    printf("\nThe elements that form an arithmetic progression have been settled\n");
                    for (int i = array_size-1; i >= 0; i--){
                        if (individual_task(*(array+i)) == 1){
                            del_array(&array, &array_size, i);
                        }
                    }
                }



                if (array_size == 0){
                    printf("all elements of the array were deleted, because the digits of each of them formed an arithmetic progression\n");
                }
                break;




            case 6:

                free(array);
                return 0;
        }
        }

    }
}



int* scanf_array(int size){
    int value = 0;
    int * array=NULL;
    array = (int*)malloc(sizeof(int) * size );
    printf("\nEnter value:\n\n");
    for (int i = 0; i < size ; i++){
        printf("[%d]: ", i);
        value = check_value_array(value);
        *(array + i) = value;
    }
    return array;
}



int individual_task(int chislo){

    int raznost = 0;
    chislo = ab(chislo);
    if (chislo >= 100){
        raznost= chislo % 10 -(chislo /10) % 10;
        chislo /= 10;
        while(chislo > 9){
            if ((chislo % 10 - (chislo /10) % 10)==raznost){
                raznost = chislo % 10 -(chislo /10) % 10;
            }
            else{
                return 0;
            }

            chislo /= 10;
        }

        return 1;
    }
    else{
        return 0;
    }
}



int check_index_array(int index){
    while ((scanf("%d",&index) != 1) || (index < 0)){
        scanf("%*[^\n]");
        printf("Incorrect data entered - index: ");
    }
    return index;
}





int check_size_array(int size){
    while ((scanf("%d",&size) != 1) || (size <= 0)){
        scanf("%*[^\n]");
        printf("Incorrect data entered - size: ");
    }
    return size;
}





int check_value_array(int value){
    while ((scanf("%d",&value) != 1)){
        scanf("%*[^\n]");
        printf("Incorrect data entered - value: ");
    }
    return value;
}




int check_indexdel_array(int inddel, int n){

    while ((scanf("%d",&inddel) != 1) || (inddel < 0) || (n - 1 < inddel)){
        scanf("%*[^\n]");
        printf("Incorrect data entered - inddel: ");
            }
    return inddel;
}





void increase_array(int **array, int *size, int index, int value){

    printf("Enter index: ");
    index = check_index_array(index);
    printf("Enter value: ");
    value = check_value_array(value);
    if (index >= *size ){
    *array = (int*)realloc(*array, sizeof(int) * ((*size) + 1));
    *((*array)+ (*size )) = 0;


    *((*array)+ (*size))  = value;
    *size = *size + 1;

    }
    else if(index >= 0 && index < *size){
        *((*array)+ index)  = value;

    }
}





void print_array(int *array, int size ) {
    printf("\noutput array:\n\n");
    for (int i = 0; i < size ; i++){
        printf("[%d]: %d ", i, *(array + i));
        printf("\n");
    }
    printf("\n");
}





int ab(int chislo){
    if (chislo < 0){
        chislo = chislo*(-1);
    }
    return chislo;
}





void del_array(int **array, int *size, int array_indexdel){


    for(int i=array_indexdel; i<*size -1; i++){
       *((*array)+ i) =*((*array)+ i+1) ;
    }
    *array = (int*)realloc(*array, sizeof(int) * (*size = *size  - 1));
}
