#include<iostream>
#include<stdint.h>
using namespace std;

//����һ������һ�㣬��1������max������ÿ������1�ĸ������������㷨���Ӷ�ΪO(N*lgN)

uint64_t numCount(int num, uint32_t n)
{
	uint64_t count = 0;
	while(n != 0)
	{
		count += (n % 10 == num) ? 1 : 0;
		n /= 10;
	}
	
	return count;
}

uint64_t f(int number, uint32_t max)
{
	uint64_t sum = 0;
	for (uint32_t i = 1; i < max; i++)
	{
		sum += numCount(number, i);
	}
	
	return sum;
}
int main()
{
	int	number;
	uint32_t max;

	cout << "number = ";

	while (cin >> number)
	{
		cout << "max = ";
		cin >> max;
		cout <<  "sum = " << f(number, max) << endl<<endl;
		cout << "number = ";
	}

}




/*
��������
1-10:�ڸ�λ�������number��ֻ�����1�Σ�
1-100����ʮλ�������number������10�Σ�
1-1000���ڰ�λ�������number������100�Σ�
��1-10^i,���������ڶ�λ��number���ǳ���10^(i-1);
���Լ���max��number���ֵĴ��������¹��ɣ�
1.ȡ��λ���ֳ���10^(i-1),�õ�A
2.ȡ��iλ��
�������number,ȡ�ұߵĵ�λ���֣���ΪB�������ΪA+B+1
���С��number,������ΪA
�������number,����ΪA+10^(i-1)
���ǣ����number��ֵΪ0����Ҫ���⿼�ǣ�
���λ���� 0
���Ӷ�O(lgN)
*/
/*
#include <stdint.h>
#include <iostream>
using namespace std;

uint64_t f( int number, uint32_t max) {
	uint64_t cnt = 0, k;
	for (uint32_t i = 1; k = max / i; i *= 10) {
		uint32_t high = k / 10;
		if (number == 0) {           
			if (high) {
				high--;
			}
			else {
				break;
			}
		}
		cnt += high * i;
		int cur = k % 10;
		if (cur > number) {
			cnt += i;
		}
		else if (cur == number) {
			cnt += max - k * i + 1;
		}
	}
	return cnt;
}

int main()
{
	int	number;
	uint32_t max;

	cout << "number = ";

	while (cin >> number)
	{
		cout << "max = ";
		cin >> max;
		cout << "sum = " << f(number, max-1) << endl << endl;
		cout << "number = ";
	}
}
*/