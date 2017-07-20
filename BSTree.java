package java_uestc;

//二叉排序树

import java.util.ArrayList;

public class BSTree {
	public int nodenum;
	public TreeNode head ;
	public ArrayList<Integer> buff;  //用于遍历时存储所有树节点的值
	private class TreeNode{
		public TreeNode lchild;
		public TreeNode rchild;
		public int value;
		public TreeNode(){
			this.value = -1;
		}
	}
	
	public BSTree(){
		this.head = new TreeNode();
		this.head.lchild = new TreeNode();
		this.head.rchild = new TreeNode();
		buff = new ArrayList<Integer>();
	}
	
	public void add(TreeNode node,int x){
		if(this.head.value == -1){
			this.head.value = x;
		}
		else if(node.value == -1){
			node.value = x;
			node.lchild = new TreeNode();
			node.rchild = new TreeNode();
		}
		else{
			if(x < node.value){
				add(node.lchild, x);
			}else{
				add(node.rchild, x);
			}
		}
	}
	
	public void merge(TreeNode head){
		this.buff.clear();
		this.print(head, 0, true);
		for(int i=0 ; i<buff.size() ; i++){
			add(this.head, buff.get(i));
		}
	}
/*
 * 按从大到小顺序遍历
 * node:要遍历树的头结点
 * thr:门限值，不小于门限值的才会被输出
 * isStore:若为true，则遍历时将遍历的结果存入到buffer
 * 		      若为false，则遍历时在控制台输出结果
 */
	public void print(TreeNode node,int thr,boolean isStore){
		if(node.rchild.value != -1){
			this.print(node.rchild,thr,isStore);
		}
		if(node.value >= thr){
			if(isStore)	this.buff.add(node.value);
			else	System.out.print(node.value+"  ");
		}
		if(node.lchild.value != -1){
			this.print(node.lchild,thr,isStore);
		}
	}
	
	public static void main(String[] args) {
		BSTree mytree = new BSTree();
		mytree.add(mytree.head, 2);
		mytree.add(mytree.head, 1);
		mytree.add(mytree.head, 5);
		mytree.add(mytree.head, 6);
		mytree.add(mytree.head, 9);
		mytree.add(mytree.head, 3);
		mytree.add(mytree.head, 4);
		mytree.print(mytree.head,0,false);
		
		System.out.println("");
		
		BSTree youtree = new BSTree();
		youtree.add(youtree.head, 7);
		youtree.add(youtree.head, 8);
		youtree.add(youtree.head, 0);
		youtree.add(youtree.head, 4);
		youtree.add(youtree.head, 10);
		youtree.print(youtree.head, 0, false);
		
		System.out.println("");
		
		mytree.merge(youtree.head);
		mytree.print(mytree.head, 0, false);
	}
}
