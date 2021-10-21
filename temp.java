 
package college;

class part implements Runnable {
	public void run()
	{
		int n, b, rev = 0;
		int N = 100;
		for (int i = 1; i <= N; i++) {
			n = i;
			while (n > 0) {
				b = n % 10;
				rev = rev * 10 + b;
				n = n / 10;
			}
			if (rev == i) {
				System.out.print(i + " ");
			}
			rev = 0;
		}
	}
}

public class prog1 {
	public static void main(String args[])
	{
			
		part ref = new part();
		Thread t = new Thread(ref);
		System.out.println("Palindrome numbers from 1 to 100 : ");
		t.run();
		try
		{
			Thread.sleep(3000);
		}
		catch (InterruptedException e)
		{
			System.out.println("\nMain thread is interrupted");
		}
		System.out.println("\nMain thread terminated");
	}
}
