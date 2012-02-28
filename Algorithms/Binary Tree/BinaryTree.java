import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

class BinaryTreeOps
{
	/** This main method is defined in the BinaryTreeOps class to demonstrate that multiple main methods
	 *	in a java program do not affect the running of the program. The JVM will look for main method only
	 *	in the class name that is mentioned while running the java program.
	 */
	static void main(String[] args)
	{
	}

	private Node root;

	private static class Node
	{
		Node left;
		Node right;
		int data;

		Node(int newData)
		{
			left = null;
			right = null;
			data = newData;
		}
	}

	public void BinaryTree()
	{
		root = null;
	}

	public void insert(int newData)
	{
		root = insert(root, newData);
	}

	private Node insert(Node root, int newData)
	{
		if(root == null)
		{
			root = new Node(newData);
		}
		else
		{
			if(newData <= root.data)
			{
				root.left = insert(root.left, newData);
			}
			else
			{
				root.right = insert(root.right, newData);
			}
		}
		return(root);
	}

	public boolean lookup(int find)
	{
		return(lookup(root, find));
	}

	private boolean lookup(Node root, int find)
	{
		if(root == null)
		{
			return (false);
		}

		if(root.data == find)
		{
			return (true);
		}
		else if(find < root.data)
		{
			return(lookup(root.left, find));
		}
		else
		{
			return (lookup(root.right, find));
		}
	}

	public void printTree()  //Print inorder
	{
		printTree(root);
		System.out.println();
	}

	private void printTree(Node root)   //Printing out tree in inorder mode.
	{
		if(root == null)
		{
			return;
		}
		else
		{
			printTree(root.left);
			System.out.print(root.data + " ");
			printTree(root.right);
		}
	}

	public void printPreOrder()
	{
		printPreOrder(root);
		System.out.println();
	}

	private void printPreOrder(Node root)
	{
		if(root == null)
		{
			return;
		}
		else
		{
			System.out.print(root.data + " ");
			printPreOrder(root.left);
			printPreOrder(root.right);
		}
	}

	public void printPostOrder()
	{
		printPostOrder(root);
		System.out.println();
	}

	private void printPostOrder(Node root)
	{
		if(root == null)
		{
			return;
		}
		else
		{
			printPostOrder(root.left);
			printPostOrder(root.right);
			System.out.print(root.data + " ");
		}
	}

	public void printBreadthFirst()
	{
		printBreadthFirst(root);
		System.out.println();
	}

	private void printBreadthFirst(Node root)
	{
		if(root==null)
		{
			return;
		}
		else
		{
			Queue<Node> queue = new LinkedList<Node>();
			queue.offer(root);
			while(!queue.isEmpty())
			{
				root = queue.remove();
				System.out.print(root.data + " ");
				if(root.left != null)
				{
					queue.offer(root.left);
				}
				if(root.right != null)
				{
					queue.offer(root.right);
				}
			}
		}
	}
	public int size()
	{
		return(size(root));
	}

	private int size(Node root)
	{
		if(root == null)
		{
			return 0;
		}
		else
		{
			return(size(root.left) + 1 + size(root.right));
		}
	}

	public int maxDepth()
	{
		return(maxDepth(root));
	}

	private int maxDepth(Node root)
	{
		if(root == null)
		{
			return 0;
		}
		else
		{
			int lDepth = 1+maxDepth(root.left);
			int rDepth = 1+maxDepth(root.right);

			//return(Math.max(lDepth, rDepth) + 1);
			if(lDepth > rDepth)
			{
				return (lDepth);
			}
			else
				return (rDepth);
		}
	}

	public int minValue()
	{
		return(minValue(root));
	}

	private int minValue(Node root)
	{
		if(root == null)
		{
			return 0;
		}
		else
		{
			Node current = root;
			while(current.left != null)
			{
				current = current.left;
			}
			return (current.data);
		}
	}

	public boolean hasPathSum(int sum)
	{
		return(hasPathSum(root, sum));
	}

	private boolean hasPathSum(Node root, int sum)
	{
		if(root == null)
		{
			return (sum == 0);
		}
		else
		{
			int subsum = sum - root.data;
			return(hasPathSum(root.left, subsum) || hasPathSum(root.right, subsum));
		}
	}

	public void printPaths()
	{
		int[] path = new int[1000];
		printPaths(root, path, 0);
	}

	private void printPaths(Node root, int[] path, int pathLen)
	{
		if(root == null)
		{
			return;
		}

		path[pathLen] = root.data;
		pathLen++;

		if(root.left == null && root.right == null)
		{
			printTreePath(path, pathLen);
		}
		else
		{
			printPaths(root.left, path, pathLen);
			printPaths(root.right, path, pathLen);
		}
	}

	private void printTreePath(int[] path, int pathLen)
	{
		for(int i=0; i<pathLen;i++)
		{
			System.out.print(path[i] + " ");
		}
		System.out.println();
	}

	public void mirror()
	{
		mirror(root);
	}

	private void mirror(Node root)
	{
		if(root == null)
		{
			return;
		}
		else
		{
			mirror(root.left);
			mirror(root.right);

			//Both the below methods are correct...

		/*	Node temp = root.left;
			root.left = root.right;
			root.right = temp;*/

			Node dup = new Node(root.data);
			dup.left = root.left;
			root.left = dup;
		}
	}

	public void doubleTree()
	{
		doubleTree(root);
	}

	private void doubleTree(Node root)
	{
		if(root == null)
		{
			return;
		}
		else
		{
			doubleTree(root.left);
			doubleTree(root.right);

			Node oldleft = root.left;
			root.left = new Node(root.data);
			root.left.left = oldleft;
		}
	}

	public boolean sameTree(BinaryTreeOps otherTree)
	{
		return(sameTree(root,  otherTree.root));
	}

	private boolean sameTree(Node root, Node otherTreeRoot)
	{
		if(root==null && otherTreeRoot==null)
		{
			return (true);
		}
		else if(root!=null && otherTreeRoot!=null)
		{
				return (root.data == otherTreeRoot.data && sameTree(root.left, otherTreeRoot.left) && sameTree(root.right, otherTreeRoot.right));
		}
		else
			return (false);
	}

	public int findParent(int childNode)
	{
		int parent = findParent(root, childNode);
		return (parent);
	}

	private int findParent(Node root, int childNode)
	{
		while(root != null && root.left != null && root.right!=null)
		{
			if(childNode == root.left.data || childNode == root.right.data)
			{
				return (root.data);
			}
			else if(childNode < root.data)
			{
				root = root.left;
			}
			else if(childNode > root.data)
			{
				root = root.right;
			}
			else
				return 0;
		}
		return (0);
	}

	public int countTrees(int numkeys)
	{
		return(counttrees(numkeys));
	}

	private int counttrees(int numkeys)
	{
		if(numkeys<=1)
		{
			return 1;
		}
		else
		{
			int sum=0, left, right, root;

			for(root=1; root<=numkeys; root++)
			{
				left = counttrees(root-1);
				right = counttrees(numkeys - root);
				sum += left*right;
			}
			return (sum);
		}
	}

/*	public int successorNode(int findSuccessor)
	{
		return (successorNode(root, findSuccessor));
	}

	private int successorNode(Node root, int findSuccessor)
	{
		if(root==null)
		{
			return 0;
		}
		else
		{
			if(root.right!=null)
			{
				return (minValue(root.right));
			}
			else
			{
				int y = findParent(findSuccessor);

				while(y && findSuccessor == )
			}
		}
	}*/
}

public class BinaryTree
{
	public static void main(String[] args)
	{
		BinaryTreeOps tree = new BinaryTreeOps();
		BinaryTreeOps tree1 = new BinaryTreeOps();

		tree.BinaryTree();
		tree1.BinaryTree();

		tree.insert(7);
		tree.insert(5);
		tree.insert(3);
		tree.insert(2);
		tree.insert(1);
		tree.insert(4);
		tree.insert(6);
		tree.insert(9);
		tree.insert(8);
		tree.insert(10);

		tree1.insert(7);
		tree1.insert(5);
		tree1.insert(3);
		tree1.insert(2);
		tree1.insert(1);
		tree1.insert(4);
		tree1.insert(6);
		tree1.insert(9);
		tree1.insert(8);

		System.out.print("Inorder Traversal : ");
		tree.printTree();  //inorder
		System.out.print("Preorder Traversal : ");
		tree.printPreOrder();
		System.out.print("Postorder Traversal : ");
		tree.printPostOrder();
		System.out.print("Breadth First Traversal : ");
		tree.printBreadthFirst();


	//	System.out.println("Printing other tree : ");
	//	tree1.printTree();

/*		System.out.println("Enter the element to find : ");
		Scanner in = new Scanner(System.in);

		int find = in.nextInt();

		if(tree.lookup(find))
		{
			System.out.println(find + " found.");
		}
		else
		{
			System.out.println(find + " not found.");
		}*/

		System.out.println("Size of Tree is : " + tree.size());
		System.out.println("Maximum depth of tree is : " + tree.maxDepth());
		System.out.println("Minimum value in the tree is : " + tree.minValue());

		/*System.out.print("Enter the sum which you want to find : ");
		int sum = in.nextInt();

		if(tree.hasPathSum(sum))
		{
			System.out.println("The root to leaf path equal to " + sum + " is found.");
		}
		else
			System.out.println("The root to leaf path equal to " + sum + " is not found.");*/

		System.out.println();
		System.out.println("Printing paths of the tree : ");
		tree.printPaths();

		/*System.out.println();
		System.out.println("Printing mirror of tree : ");
		tree.mirror();
		tree.printTree();*/

		/*System.out.println();
		System.out.println("Doubling the tree : ");
		tree.doubleTree();
		tree.printTree();
		tree.printPreOrder();
		tree.printPostOrder();*/

		System.out.println();
		System.out.println("Checking if two trees are the same : ");
		if(tree.sameTree(tree1))
		{
			System.out.println("The trees are same..");
		}
		else
			System.out.println("The trees are not same..");

		System.out.println();
		Scanner in = new Scanner(System.in);
		System.out.print("Enter the root to find parent : ");
		int findParentNode = in.nextInt();
		int parent = tree.findParent(findParentNode);
		if(parent == 0)
		{
			System.out.println("Node " + findParentNode + " does not have any parent.");
		}
		else
		{
			System.out.println("Parent node of " + findParentNode + " is : " + parent);
		}

		System.out.println();
		System.out.println("Enter the number of keys to find out possible number of trees");
		int numkeys = in.nextInt();
		int totalTrees = tree.countTrees(numkeys);
		System.out.println("The number of trees for " + numkeys + " number of keys is " + totalTrees);

//		System.out.println();
//		System.out.print("Enter the node to find the successor : ");
//		int findSuccessor = in.nextInt();
//		int successorOfNode = tree.successorNode(findSuccessor);
	}
}

