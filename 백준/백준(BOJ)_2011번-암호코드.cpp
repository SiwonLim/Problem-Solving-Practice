#include <iostream>
#include <string>
using namespace std;
long long d[5001];
long long code[5001];
int main()
{
	string num;
	getline(cin, num);
	int size = num.size();
	if (size > 5000) exit(-1);
	for (int i = 0; i < size ; i++) code[i+1] = num[i] - '0';
	
	if ((num[0] - '0' == 0) && size==1) cout << 0 << endl;
	else
	{
		d[0] = 1;
		for (int i = 1; i <= size ; i++)
		{
			if (code[i] >= 1 && code[i] <= 9)
				d[i] = (d[i] + d[i - 1]) % 1000000;

			int twoDigit = code[i - 1] * 10 + code[i];
			
			if (twoDigit >= 10 && twoDigit <= 26)
				d[i] = (d[i] + d[i - 2]) % 1000000;
		}
		
		cout << d[size] << endl;
	}
	return 0;
}