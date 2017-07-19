package java_uestc;

//双向循环队列==》输出受限（队首输出·）

//每一个元素用一个整型数，表示任务的预计时间
public class Biqueue {
	private int rear;
	private int front;
	private int[] data;
	private static final int SIZE = 10;
	public Biqueue(){
		data = new int[Biqueue.SIZE];
		this.rear = 0;
		this.front = 0;
		
	}
	private boolean isFull(){  //调试用，完事后记得改回private
		if((this.rear+1)%Biqueue.SIZE == this.front){
			return true;
		}
		return false;
	}
	private boolean isEmpty(){  //调试用，完事后记得改回private
		if(this.rear == this.front){
			return true;
		}
		return false;
	}
	private void print(){
		int temp_front = this.front;
		while(temp_front != rear){
			temp_front = (temp_front+1)%Biqueue.SIZE;
//			System.out.println("-----------");
			System.out.println(this.data[temp_front]);
		}
	}
	public void enQueue(int x){
		if(!(this.isFull())){
			if(this.isEmpty()){
				this.rear = (this.rear+1)%Biqueue.SIZE;
				this.data[this.rear] = x;
			}
			else{
				if(x < (this.data[this.rear]+this.data[(this.front+1)%Biqueue.SIZE])/2){//队头插入
					System.out.println("队头插入："+x);
					this.data[this.front] = x;
					this.front = (this.front-1+Biqueue.SIZE)%Biqueue.SIZE;
				}else{
					System.out.println("队尾插入："+x);
					this.rear = (this.rear+1)%Biqueue.SIZE;
					this.data[this.rear] = x;
				}
			}
		}else{
			System.out.println("队满了，不能再入队了。");
		}
	}
	public int deQueue(){
		if(!(this.isEmpty())){
			this.front = (this.front+1)%Biqueue.SIZE;	
			return this.data[this.front];
		}
		else{
			System.out.println("队空，不能再出队了。");
			return -1;
		}
	}
	
	public static void main(String[] args) {
		Biqueue queue = new Biqueue();
		queue.enQueue(1);
		queue.print();
		System.out.println("---");
		queue.enQueue(3);
		queue.print();
		System.out.println("---");
		queue.enQueue(3);
		queue.print();
		System.out.println("---");
		queue.enQueue(1);
		queue.print();
		System.out.println("---");
		queue.deQueue();
		queue.print();
	}
}
