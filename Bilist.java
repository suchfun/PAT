package java_uestc;

public class Bilist {
	
	public int size;
	public Node header = new Node();
	
	private class Node{
		public Node(){}
		public  Node (Node pre, Node next, Object data, int freq) {
			this.pre = pre;
			this.next = next;
			this.data = data;
			this.freq = freq;
		}
		public Node pre;
		public Node next;
		public Object data;
		public int freq;
	}
	public Bilist(){
		//Node header = new Node(header,header,null,0);
		this.header.pre = this.header;
		this.header.next = this.header;
		this.header.data = "header";
		this.size=0;
	}
	public void add(Object o){
		Node element = new Node(this.header.pre,this.header,o,0);
		this.header.pre.next = element;
		this.header.pre = element;
		this.size++;
	}
	public void print(){
		Node temp = this.header.next;
		if(this.size > 0){
			System.out.println(this.header.data+"'freq==>"+this.header.freq+"  pre==>"+this.header.pre.data+"  next==>"+this.header.next.data);
			while(temp != this.header){
				System.out.println(temp.data+"'freq==>"+temp.freq+"  pre==>"+temp.pre.data+"  next==>"+temp.next.data);
				temp = temp.next;
			}
		}
	}
	public Object locate(int index){
		int i=0;
		Node temp = this.header;
		while(i < index){
			temp = temp.next;
			i++;
		}
		temp.freq++;
		this.sort();
		return temp.data;
	}
	private void sort(){//选择排序  
		if(this.size >= 2){
			Node model = this.header.next;	
			while(model.next != this.header){			
				Node max = model;
				Node temp_model = model;
				Node key = model.next;
				while(key != this.header){			
					if(key.freq > max.freq){
						max = key;
					}
					key = key.next;				
				}				
//				Object temp_obj = max.data; int temp_freq = max.freq;
//				max.data = temp_model.data; max.freq = temp_model.freq;
//				temp_model.data = temp_obj; temp_model.freq = temp_freq;
//				model = model.next;	
				
				Node temp_pre = max.pre; Node temp_next = max.next;
				//当两个要交换的Node相邻时，要分开讨论！！
				if(temp_model.next == max){
					max.pre = temp_model.pre; max.next = temp_model;temp_model.pre.next = max;
					temp_model.pre = max; temp_model.next = temp_next;temp_next.pre = temp_model;
				}
				else{
					max.pre = temp_model.pre; max.next = temp_model.next;temp_model.pre.next = max;temp_model.next.pre = max;
					temp_model.pre = temp_pre; temp_model.next = temp_next;temp_pre.next = temp_model;temp_next.pre = temp_model;
				}
				
				model = max.next;
				
			}
		}
	}
	
	public static void main(String [] args){
		Bilist list = new Bilist();
		list.add("suchfun");
		list.add("hello");
		list.add("world");
		list.print();
		list.locate(2);
		System.out.println("-----");
		list.print();
		list.locate(3);
		System.out.println("-----");
		list.print();

	}
}

