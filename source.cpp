#include<iostream>
#include<stdint.h>
using namespace std;

//方法一：暴力一点，从1遍历到max，，将每个数中1的个数加起来，算法复杂度为O(N*lgN)

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
方法二：
1-10:在个位，任意的number都只会出现1次；
1-100：在十位，任意的number都出现10次；
1-1000：在百位，任意的number都出现100次；
即1-10^i,在往右数第二位上number都是出现10^(i-1);
所以计算max中number出现的次数有如下规律：
1.取高位数字乘以10^(i-1),得到A
2.取第i位：
如果等于number,取右边的低位数字，设为B，最后结果为A+B+1
如果小于number,则结果就为A
如果大于number,则结果为A+10^(i-1)
但是：如果number的值为0，需要另外考虑：
最高位不含 0
复杂度O(lgN)
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