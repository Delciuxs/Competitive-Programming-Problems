#LINK to the Problem:
#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=365
#Problem type: Big Interger

from sys import stdin, stdout

def main():
	number = stdin.readline()
	number = int(number)
	total_sum = 0
	while(number != 0):
		total_sum += number
		number = stdin.readline()
		number = int(number)

	stdout.write(str(total_sum) + "\n")

main()	