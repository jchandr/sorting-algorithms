#include "definition.cpp"

int main()
{
	int no_of_elements=0;
	char exit_choice='y';
	int limit=0;

	do
	{
		cout << "\nEnter the number of elements you want to generate: ";
		cin >> no_of_elements;
		cout << "\n Enter the limit of Numbers: ";
		cin >> limit;
		generate_random_number_array(limit,no_of_elements);
		cout << "The Numbers before sorting are: ";
		print_array(random_number_array,no_of_elements);
		print_with_asterix(random_number_array,no_of_elements);
		char choice = display_menu_and_get_choice();
		switch(choice)
		{
			case '1':
			{
				insertion_sort(random_number_array,no_of_elements);
				break;
			}
			case '2':
			{
				if(limit < 100)
					counting_sort(random_number_array,no_of_elements);
				else
					cout << "\nCounting Sort Not supported\n";
				break;
			}
			case '3':
			{
				merge_sort(random_number_array,no_of_elements);
				break;
			}
			case '4':
			{
				randomized_quick_sort(random_number_array,no_of_elements);
				break;
			}
			default:
			{
				cout << "Invalid Option.";
				break;
			}
		}
		cout << "\n Numbers after sorting are: ";
		print_array(random_number_array,no_of_elements);
		print_with_asterix(random_number_array,no_of_elements);
		cout << "\nDo you wish to continue? Y/n : ";
		cin >> exit_choice;
	} while (exit_choice != 'n' && exit_choice != 'N');
	cout << "\n\n Bubbye !\n\n";
	return 0;
}