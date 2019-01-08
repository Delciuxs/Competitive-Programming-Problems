#LINK to the Problem:
#https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2921
#Problem type: Big Integer

def main():
	t = 0
	t = int(input())

	for i in range(t):

		numbers = []#store decimal numbers
		numbers_without_points = []
		numbers_points = []#positions of the point in every decimal number
		numbers_digits_after_point = []#digits after the point in every decimal number
		digits_after_point = 0
		max_digits_after_point = 0
		number = ""
		number_decimal = 0
		sum_total = 0
		final_point = 0

		decimal_number = input()

		while decimal_number != '0':
			flag = 0
			for j in  range(len(decimal_number)):
				if(decimal_number[j] == '.'):#find the point in the number
					flag  = 1
					digits_after_point = len(decimal_number) - j - 1
					numbers_digits_after_point.append(digits_after_point)
					numbers_points.append(j)
					numbers.append(decimal_number)

					if(digits_after_point > max_digits_after_point):#obtaining the max digits_after_point
						max_digits_after_point = digits_after_point
			if(flag == 0):#if the input is a number without point
				digits_after_point = 0
				numbers_digits_after_point.append(digits_after_point)
				numbers_points.append(len(decimal_number)+1)
				numbers.append(decimal_number)
			decimal_number = input()

		for j in range(len(numbers)):#for every number take out the point of the string
			numbers[j] = numbers[j][:numbers_points[j]] + numbers[j][numbers_points[j]+1:]
						
		for j in range(len(numbers)):#complete with zeroes the right side till we have the same digits_after_point (max_digits_after_point)for every number
			add_zeroes = max_digits_after_point - numbers_digits_after_point[j]
			for k in range(add_zeroes):
				numbers[j] += '0'

		for j in range(len(numbers)):#convert every string number into a integer and store them
			number = numbers[j]
			number_decimal = int(number)
			numbers_without_points.append(number_decimal)

		sum_total = sum(numbers_without_points)#make the sum of the integer numbers
		sum_total = str(sum_total)

		final_point = len(sum_total) - max_digits_after_point#find the position in the string where the point needs to be added

		if(final_point < 0):#add zeroes to the left if the final point is negative
				result = "0."  
				for i in range(abs(final_point)):
					result += "0"
				result += sum_total

				j = len(result) -1#find a right limit boundary (eliminate zeroes at right)
				while(result[j] == '0'):
					j = j - 1
				
				if(result[j] == '.'):#eliminate the point if it is at the end
					result = result[:j]
				else:
					result = result[:j+1]

				print(result)	

		else:#if not just paste the point where it has to be
			result = sum_total[:final_point] + "." + sum_total[final_point:]
			
			j = len(result) -1#find a right limit boundary (eliminate zeroes at right)
			while(result[j] == '0'):
				j = j - 1
			
			if(result[j] == '.'):#eliminate the point if it is at the end
				result = result[:j]
			else:
				result = result[:j+1]

			if(result[0] == '.'):#if the first char of the string is a point we need to add firts an 0 for obtaining 0.
				result = "0" + result

			print(result)

main()