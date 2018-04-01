import java.util.*;
import java.math.BigInteger;

public class k_based_numers_v2
{
	static int n;

	static BigInteger k = new BigInteger("0");

	static BigInteger solve(int past_number, int actual_number,int level, BigInteger memory[][])
	{
		BigInteger aux = new BigInteger("0");

		if(past_number + actual_number == 0)
			return BigInteger.ZERO;

		else if(level == n)
			return BigInteger.ONE;

		else if(memory[level][actual_number] == BigInteger.ZERO)
			memory[level][actual_number] = solve(actual_number, 0, level + 1, memory).add(solve(actual_number, 1, level + 1, memory).multiply(k.subtract(BigInteger.ONE)));

		return memory[level][actual_number];
	}

	public static void main(String args[])
	{
		Scanner reader = new Scanner(System.in);

		BigInteger ans = new BigInteger("0");	

		n = reader.nextInt();

		k = reader.nextBigInteger();

		BigInteger memory[][] = new BigInteger[n + 1][3];

		for(int i = 0; i < n + 1; i++)
			for(int j = 0; j < 3; j++)
				memory[i][j] = BigInteger.ZERO;
			

		ans = solve(0,1,1, memory).multiply(k.subtract(BigInteger.ONE));

		System.out.println(ans);
	}
}
