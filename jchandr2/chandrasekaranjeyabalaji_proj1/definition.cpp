#include "prototype.h"

// Sorting method definition
int insertion_sort(int elements[],int no_of_elements)
{
	if(no_of_elements<2)
		return 0;
	for(int i=1;i < no_of_elements;i++)
	{
		int temp_value = elements[i];
		int j = i - 1;
		while(j >= 0 && elements[j] > temp_value)
		{
			elements[j+1] = elements[j];
			j--;
		}
		elements[j+1] = temp_value;
	}

	return 1;
}

int counting_sort( int* elements, int no_of_elements)
{
	int min, max, z = 0; 

	if(no_of_elements < 2)
	{
		cout << "Only one element in the array.";
		return 0;
	}

	find_min_and_max( elements, no_of_elements, min, max );
	int nlen = ( max - min ) + 1; int* temp = new int[nlen];
	memset( temp, 0, nlen * sizeof( int ) );

	for( int i = 0; i < no_of_elements; i++ ) 
		temp[elements[i] - min]++;

	for( int i = min; i <= max; i++ )
	{
		while( temp[i - min] )
		{
			elements[z++] = i;
			temp[i - min]--;
		}
	}

	delete [] temp;
	return 1;
}

int randomized_quick_sort(int *elements, int no_of_elements)
{
	srand(time(NULL));
	int i, j, pivot, t;
    if (no_of_elements < 2)
        return 0;
    int temp = rand() % no_of_elements;
    pivot = elements[temp];
    for (i = 0, j = no_of_elements - 1;; i++, j--) {
        while (elements[i] < pivot)
            i++;
        while (pivot < elements[j])
            j--;
        if (i >= j)
            break;
        t = elements[i];
        elements[i] = elements[j];
        elements[j] = t;
    }
    randomized_quick_sort(elements, i);
    randomized_quick_sort(elements + i, no_of_elements - i);
    return 1;
}

int generate_random_number_array(int limit,int no_of_elements)
{
	srand(time(NULL));

	for(int i=0;i<no_of_elements;i++)
		random_number_array[i] = 0;

	for(int i=0;i<no_of_elements;i++)
		random_number_array[i] = rand() % limit;

	return 1;
}

int merge (int *a, int n, int m) 
{
    int i, j, k;
    int *x = (int*)malloc(n * sizeof(int));
    for (i = 0, j = m, k = 0; k < n; k++) 
    {
        x[k] = j == n      ? a[i++]
             : i == m      ? a[j++]
             : a[j] < a[i] ? a[j++]
             :               a[i++];
    }
    for (i = 0; i < n; i++) 
    {
        a[i] = x[i];
    }
    free(x);
    return 1;
}
 
int merge_sort (int *elements, int no_of_elements) 
{
    if (no_of_elements < 2)
        return 0;
    int m = no_of_elements / 2;
    merge_sort(elements, m);
    merge_sort(elements + m, no_of_elements - m);
    merge(elements, no_of_elements, m);
    return 1;
}

// Helper function definition

void swap_int(int x,int y)
{
	int temp=0;
	temp = x;
	x = y;
	y = temp;
}

char display_menu_and_get_choice()
{
	char choice_;
	
	cout << endl << "\n1. Insertion Sort";
	cout << "\n2. Counting Sort";
	cout << "\n3. Merge Sort";
	cout << "\n4. Randomized Quick Sort";
	cout << "\nWhich sorting algorithm do you want to use for sorting? ";
	cin >> choice_;
	return choice_;
}

void find_min_and_max( int* elements, int no_of_elements, int& min, int& max)
{
	min = INT_MAX; max = 0;
	for( int i = 0; i < no_of_elements; i++ )
	{
	    if( elements[i] > max ) 
	    	max = elements[i];
	    if( elements[i] < min ) 
	    	min = elements[i];
	}
}

void print_with_asterix(int elements[],int no_of_elements)
{
	if(no_of_elements < 20)
	{
		cout << "\n\nAsterix Representation\n";
		for(int i=0;i<no_of_elements;i++)
		{
			if(elements[i] != 0)
			{
				for(int j=0;j<elements[i];j++)
				{
					cout << "*";
				}
			}
			else
				cout << "-";
			cout << "\n";
		}
	}
}

int print_array(int array[],int no_of_elements)
{
	cout << "\n\n";
	for(int i=0;i < no_of_elements;i++)
	{
		cout << array[i] << ",";
	}
	return 1;
}
