#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int random_number_array[1000];
int instruction_count=0;

//sorting methods prototype
int insertion_sort(int elements[],int no_of_elements);
int counting_sort( int* elements, int no_of_elements );
int randomized_quick_sort(int *elements,int no_of_elements);
int merge (int *a, int n, int m);
int merge_sort (int *elements, int no_of_elements);

//helper methods prototype
void find_min_and_max( int* elements, int no_of_elements, int& min, int& max);
void swap_int(int x, int y);
int generate_random_number_array(int limit,int no_of_elements);
int print_array(int array,int no_of_elements);
char display_menu_and_get_choice();
void print_with_asterix(int elements[],int no_of_elements);