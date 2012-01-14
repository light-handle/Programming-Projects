package Source;

import java.util.Random;

public class MergeSort
{
	public static void main(String[] args)
	{
		int SIZE = 8;
	    int MAX=40;
	    int m = 0;

		int[] Array = new int[SIZE];

		Random generator = new Random();

		for(m=0; m<Array.length; m++)
		{
			Array[m] = generator.nextInt(MAX);
		}

		System.out.println("Before Sort: ");
		for(m=0; m<Array.length; m++)
		{
			System.out.print(Array[m]+" ");
		}
		System.out.println("\n");

		Mergesorter sorter = new Mergesorter();
		sorter.sort(Array);

		System.out.println("After Sort: ");

		for(m=0; m<Array.length; m++)
		{
			System.out.print(Array[m]+" ");
		}
	}
}

class Mergesorter
{
	public static int SIZE = 8;
    int i = 0;
	int j = 0;

	public int[] Array = new int[SIZE];

    int number;

    void sort(int[] Array)
	{
		this.Array = Array;
		number=Array.length;
		System.out.println("Length:"+number+"\n");

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
		int i=0, j=0, k=0;
		int[] b = new int[SIZE];

		for(i=low; i<=high; i++)
		{
			b[i] = A[i];
		}

		i=low; j=middle+1; k=low;

		while(i<=middle && j<=high)
		{
			if (b[i]<=b[j])
			{
				A[k++] = b[i++];
			}
			else
			{
				A[k++] = b[j++];
			}
		}

		while (i<=middle)
		{
			A[k++] = b[i++];
		}
	}
}