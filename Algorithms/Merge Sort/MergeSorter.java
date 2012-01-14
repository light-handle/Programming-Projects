package Source;
import java.util.Random;

public class MergeSorter
{
	public static int SIZE = 8;
    int i = 0;
	int j = 0;

	public int[] Array = new int[SIZE];

    int number;

	public void sort(int[] Array)
	{
		this.Array = Array;
		number=Array.length;

		mergesort(Array, 0, number-1);
	}

	public void mergesort(int[] Array, int low, int high)
	{
		if(low<high)
		{
			int middle = (high+low)/2;

			mergesort(Array, low, middle);

			mergesort(Array, middle+1, high);

			merge(Array, low, middle, high);
		}
	}

	public void merge(int[] A, int low, int middle, int high)
	{
		int n1 = middle-low+1;
		int n2 = high-middle;

		int[] L = new int[n1+1];
		int[] R = new int[n2+1];

		for(int i=0;i<n1;i++)
		{
			L[i] = A[low+i];
		}

		for (int j=0;j<n2;j++)
		{
			R[i] = A[middle+j];
		}

		L[n1+1] = -1;
		R[n2+1] = -1;

		i=0;
		j=0;

		for(int k=low; k<high; k++)
		{
			if(L[i] <= R[j])
			{
				A[k] = L[i];
				i++;
			}
			else
			{
				A[k] = R[j];
				j++;
			}
		}
	}
}