#LINK to the Problem:
#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3671
#Problem type: Big Interger

def main():
	t = int(input())
	for i in range(t):
		x, y , z = map(int, input().split())
		print(pow(x,y,z))

main()