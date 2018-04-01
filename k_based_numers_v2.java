import java.util.*;
import java.math.BigInteger;

public class k_based_numers_v2
{
	static int n, k;

	static BigInteger solve(int past_number, int actual_number,int level, BigInteger memory[][])
	{
		BigInteger aux = new BigInteger("0");

		if(past_number + actual_number == 0)
			return BigInteger.ZERO;

		else if(level == n)
			return BigInteger.ONE;

		else if(memory[level][actual_number] == BigInteger.ZERO)
		{
			for(int s = 0; s < k; s++)
			{
				aux = aux.add(solve(actual_number, s, level + 1, memory));

				memory[level][actual_number] = aux;
			}
		}

		return memory[level][actual_number];
	}

	public static void main(String args[])
	{
		Scanner reader = new Scanner(System.in);

		BigInteger ans = new BigInteger("0");	

		n = reader.nextInt();

		k = reader.nextInt();

		BigInteger memory[][] = new BigInteger[n + 3][k + 3];

		for(int i = 0; i < n + 1; i++)
			for(int j = 0; j < k; j++)
				memory[i][j] = BigInteger.ZERO;
			

		for(int i = 1; i < k; i++)
		{
			ans =  ans.add(solve(0, i, 1, memory));
		}

		System.out.println(ans);
	}
}