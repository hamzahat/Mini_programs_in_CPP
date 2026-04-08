#include <iostream>

//* print arr:
void ft_print_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

//* swap
void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

//* sort arr:
void sort_arr(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) //! remark: change this '>' with '<' to reverse the sorting
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

int main()
{
	int arr[] = {10, 1, 9, 8, 7, 4, 5, 2, 3, 6};
	int size = sizeof(arr) / sizeof(arr[0]);

	//* print the arr before sort it:
	std::cout << "before sorting:\n";
	ft_print_arr(arr, size);
	
	//* sort the arr:
	sort_arr(arr, size);
	//* print the arr after sorting:
	std::cout << "after sorting:\n";
	ft_print_arr(arr, size);
	return 0;
}
