//LINK to the Problem:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=976
//Problem type: Big Interger

#include<iostream>
using namespace std;

int main()
{
	string num1, num2;
	cin >> num1 >> num2;

	while(1)
	{
		int carry_total = 0, add_zeroes = 0, aux_carry = 0, sum = 0;
		string new_num1 = "", new_num2 = "";

		//If the two strings are 0 stop reading test cases
		if(num1 == "0" && num2 == "0")
			break;
	
		//If the strings are different...
		if(num1.size() != num2.size())
		{
			//Add zeroes to the left of the num1, because is shorter than num2			
			if(num1.size() > num2.size())
			{	
				add_zeroes = num1.size() - num2.size();
				for(int i = 0; i < add_zeroes; i++)
				{
					new_num2 += '0';
				}
				new_num2 += num2;
				num2 = new_num2;
			}
			//Or add zeroes to the left of the num2, because is shorter than num1
			else
			{
				add_zeroes = num2.size() - num1.size();
				for(int j = 0; j < add_zeroes; j++)
				{
					new_num1 += '0';
				}
				new_num1 += num1;
				num1 = new_num1;
			}
		}

		for(int i = num1.size()-1; i >= 0; i--)
		{
			//Sum each pair of the numbers considering the carry
			sum = num1[i] - '0' + num2[i] - '0' + aux_carry;
			if(sum > 9)
			{
				carry_total++;
				aux_carry = 1;
			}
			else
				aux_carry = 0;
		}

		if(carry_total == 0)
			cout << "No carry operation." << endl;
		else if(carry_total == 1)
			cout << carry_total << " carry operation." << endl;
		else
			cout << carry_total << " carry operations." << endl;

		cin >> num1 >> num2;
	}
	return 0;
}