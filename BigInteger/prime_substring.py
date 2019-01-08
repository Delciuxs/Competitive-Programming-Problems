#LINK to the Problem:
#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3987
#Problem type: Big Integer

def Prime_Sieve(n):
	primes = []
	sieve = [0] * (n+1)
	primes.append(2)
	for i in range(2,n+1,2):
		sieve[i] = 1
	for i in range(2,n+1):
		if(sieve[i] == 0):
			primes.append(i)
			for j in range(i,n+1, i):
				sieve[j] = 1

	return primes

def Find_Result(check_primes, number):
	for num in check_primes[::-1]:
			for i in range(5,0,-1):
				for j in range(0,len(number)-i+1,1):
					if(num == int(number[j:j+i])):
						return num
					



def main():
	check_primes = Prime_Sieve(100000)
	number = input()
	while(number != "0"):
		print(Find_Result(check_primes, number))
		number = input()
	

main()

