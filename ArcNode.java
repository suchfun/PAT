package java_uestc;

public class ArcNode{
	public int weight;
	public int nextArcNo;  //下一条边
	public int toNode;   //指向哪一个顶点
	public ArcNode(int weight,int nextArcNo,int toNode){
		this.weight = weight;
		this.nextArcNo = nextArcNo;
		this.toNode = toNode;
	}
}
