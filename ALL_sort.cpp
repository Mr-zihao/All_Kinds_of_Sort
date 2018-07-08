#include <iostream>
#include <vector>
#include <stdlib.h>
#define Random(x) (rand() % x)
using namespace std;
void Bubble_Sort(vector<int> & num, bool decend = true);
void Select_Sort(vector<int> & num, bool decend = true);
void Insert_Sort(vector<int> & num, bool decend = false);
void Fast_Sort  (vector<int> & num, int start, int end);
void Merge_Sort(vector<int> &num, int low, int high);
void merge(vector<int> &num, int low, int mid, int high);
void swap(int & a, int & b);
int main()
{	
	vector<int> b;
	for (int i = 0; i < 10; i++)
	{
		b.push_back(Random(10));
	}
	/*cout << b[0] << b[1] << endl;
	swap(b[0], b[1]);
	cout << b[0] << b[1] << endl;*/
	
	Merge_Sort(b,0,b.size()-1);
	for (int i = 0; i<b.size(); i++)
	{
		cout << b[i] << endl;
	}
	system("pause");
	return 0;
}

// ...................................Bubble_Sort

void Bubble_Sort(vector<int> & num ,bool decend)
{
	int temp;
	if (decend)
	{
		for (int i = 0; i < num.size() - 1; i++)
		{
			for (int j = 0; j < num.size() - 1 - i; j++)
			{
				if (num[j] < num[j + 1])
				{
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < num.size() - 1; i++)
		{
			for (int j = 0; j < num.size() - 1 - i; j++)
			{
				if (num[j] > num[j + 1])
				{
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}
		}
	}
}

// .................................Select_Sort

void Select_Sort(vector<int> & num, bool decend)
{
	int max_temp;
	int max_index;
	int temp;
	int min_temp;
	int min_index;
	int temp1;
	if (decend)
	{
		
		for (int i = 0; i < num.size() - 1; i++)
		{
			max_temp = num[i];
			max_index = i;
			for (int j = i + 1; j < num.size(); j++)
			{
				if (num[j] > max_temp)
				{
					max_temp = num[j];
					max_index = j;
				}
			}
			temp = num[i];
			num[i] = max_temp;
			num[max_index] = temp;
		}
	}
	else
	{
		
		for (int i = 0; i < num.size() - 1; i++)
		{
			min_temp = num[i];
			min_index = i;
			for (int j = i + 1; j < num.size(); j++)
			{
				if (num[j] < min_temp)
				{
					min_temp = num[j];
					min_index = j;
				}
			}
			temp1 = num[i];
			num[i] = min_temp;
			num[min_index] = temp1;
		}


	}

}

//.............................Insert_Sort

void Insert_Sort(vector<int> & num, bool decend)
{
	if (decend)
	{
		for (int i = 1; i < num.size(); i++)
		{
			int key = num[i];
			int j = i - 1;
			while (j >= 0 && key < num[j])
			{
				num[j + 1] = num[j];
				j--;
			}
			num[j + 1] = key;
		}
	}
	else
	{
		for (int i = 1; i < num.size(); i++)
		{
			int key = num[i];
			int j = i - 1;
			while (j >= 0 && key > num[j])
			{
				num[j + 1] = num[j];
				j--;
			}
			num[j + 1] = key;
		}


	}
  
  
}
// ............................Fast_Sort

void Fast_Sort  (vector<int> & num, int start, int end)
{
	if (start >= end)
		return;
	int key = num[end];
	int left = start;
	int right = end - 1;
	while (1)
	{
		while (num[left] < key)
		{
			++left;
			
		}
		while (num[right] >= key)
		{
			--right;
			if (right < start)
			{
				right = start;
				break;
			}
		}
		if (left >= right)
			break;
		swap(num[left], num[right]);
	}
	swap(num[left], num[end]);
	Fast_Sort(num, start, left - 1);
	Fast_Sort(num, left + 1, end);
}
void swap(int & a, int & b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

// .......................Merge_Sort

void Merge_Sort(vector<int> &num, int low, int high)
{
	int mid = (low + high) / 2;
	if (low < high)
	{
		Merge_Sort(num, low, mid);
		Merge_Sort(num, mid+1, high);
		merge(num, low, mid, high);
	}
}
void merge(vector<int> &num, int low, int mid, int high)
{
	vector<int> temp;
	int i = low;
	int j = mid + 1;
	int k = 0;
	while (i <= mid&&j <= high)
	{
		if (num[i] < num[j])
			temp.push_back(num[i++]);
		else
			temp.push_back(num[j++]);
	}
	while (i <= mid)
	{
		temp.push_back(num[i++]);
	}
	while (j <= high)
	{
		temp.push_back(num[j++]);
	}
	for (int k2 = 0; k2 < temp.size(); k2++)
	{
		num[k2 + low] = temp[k2];
	}
}
