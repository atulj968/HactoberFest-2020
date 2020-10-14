//.h file code:

#include <string>
#include <vector>
#include <iostream>

class Test
{
public:
	virtual int bit(int n);
	static void main(std::vector<std::wstring> &args);
};

//.cpp file code:

int Test::bit(int n)
{
	int min = 999, max = 0;
	while (n != 0)
	{
		int rem = n % 10;
		if (min > rem)
		{
			min = rem;
		}
		if (max < rem)
		{
			max = rem;
		}
		n = n / 10;
	}
	int ans = (max * 11 + min * 7) % 100;
	return ans;
}

void Test::main(std::vector<std::wstring> &args)
{
	int i, j, size, pairs = 0;
	Scanner *s = new Scanner(System::in);
	Test *obj = new Test();
	size = s->nextInt();
	std::vector<int> arr(size);
	for (i = 0 ;i < size; i++)
	{
		arr[i] = s->nextInt();
		arr[i] = obj->bit(arr[i]);
	}
	for (i = 0 ;i < size; i++)
	{
		for (j = i + 2; j < size; j += 2)
		{
			if (arr[i] / 10 == arr[j] / 10)
			{
				pairs++;
				break;
			}

		}
	}
	std::wcout << pairs;

	delete obj;
	delete s;
}
