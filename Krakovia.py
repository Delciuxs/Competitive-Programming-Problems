#LINK to the Problem:
#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1866
#Problem type: Big Interger

#We need funtion Fractions for a good aproximation for a division
from fractions import Fraction 

def main():
	cont = 0
	while 1 :
		query = input()
		items, friends = query.split()
		items = int(items)
		friends = int(friends)
		prize_items = []
		total = 0
		cont = cont + 1
		if(items == 0 and friends == 0):
			break
		for i in range(0,items):
			prize_items.append(input())
		for i in range(0,items):
			total += int(prize_items[i])
		individual = Fraction(total,friends)
		print("Bill #" +str(cont) + " costs " + str(total) + ": each friend should pay " + str(int(individual)))
		print("")
main()
