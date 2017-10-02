#LINK to the Problem:
#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1464
#Problem type: Big Interger

#We need funtion pow for a good aproximation

import math
import sys


def main():
	for query in sys.stdin:
		n, a = query.split()
		n = int(n)
		a = int(a)
		total_sum = 0

		for i in range(1, n + 1):
			total_sum += int(i*pow(a,i))
		print(str(total_sum))
main()
