import java.util.*;
import java.util.concurrent.Semaphore;
class SharedResources{
	int in=0;
	int out=0;
	int []buffer =new int[10];
	static Semaphore sp=new Semaphore(1);
	static Semaphore sc=new Semaphore(0);
}
class Producer extends SharedResources implements Runnable{
	public void run(){
		try{
			while(true){
				try{
					sp.acquire();
				}catch(Exception e){}
				buffer[in]=1;
				in =(in+1)%10;
				System.out.println("producer produced 'in' pointing to "+in+" in the buffer");
				sc.release();
			}
		}catch(Exception e){}
	}
}
class Consumer extends SharedResources implements Runnable{
	public void run(){
		try{
			while(true){
				try{
					sc.acquire();
				}catch(Exception e){}
				buffer[out]=0;
				out=(out+1)%10;
				System.out.println("consumer consumed 'out' pointing at "+out+" in the buffer");
				sp.release();
			}
		}catch(Exception e){}
	}
}
class Process1 implements Runnable{
	public void run(){
		try{
			while(true){
				seemantPetersonSolution.flag[0]=true;
				seemantPetersonSolution.turn=true;
				while(seemantPetersonSolution.flag[1] && seemantPetersonSolution.turn==true){
					System.out.println("process1 waiting...");
				}
				seemantPetersonSolution.c+=1;
				System.out.println("process1 increments the value of c , current value "+seemantPetersonSolution.c);
				seemantPetersonSolution.flag[0]=false;
			}
		}catch(Exception e){}
	}
}
class Process2 implements Runnable{
	public void run(){
		try{
			while(true){
				seemantPetersonSolution.flag[1]=true;
				seemantPetersonSolution.turn=false;
				while(seemantPetersonSolution.flag[0]==true && seemantPetersonSolution.turn==false){
					System.out.println("process2 waiting....");
				}
				seemantPetersonSolution.c-=1;
				System.out.println("process2 decrement the value of c , current value "+seemantPetersonSolution.c);
				seemantPetersonSolution.flag[1]=false;
			}
		}catch(Exception e){}
	}
}
class seemantPetersonSolution {
	static int c;
	static boolean turn;
	static boolean[] flag=new boolean[2];
    public static void main(String[] args) {
			Thread p1=new Thread(new Process1());
			Thread p2=new Thread(new Process2());
			//p1.start(); //threads for question 1
			//p2.start();
			Thread producer=new Thread(new Producer());
			Thread consumer=new Thread(new Consumer());
			producer.start();
			consumer.start();
    }
}