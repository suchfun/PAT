package java_uestc;

import java.util.ArrayList;
/*
 * A->B->C   	第0和第1条arc  权重为1和2
 * B->C->D->E  	2,3,4 -> 2,5,1
 * C->D->E		5,6 -> 4,2
 * D->E			7 -> 2
 * E->F			8 -> 3
 * F->D			9 -> 3
 */
public class AdjGragh {//邻接表
	
	public ArrayList<ArcNode> arcs = new ArrayList<ArcNode>();
	public ArrayList<VNode> nodes = new ArrayList<VNode>();
	public int arcnum;
	public int nodenum;
	public static final char[] NUM2EN = {'A','B','C','D','E','F'};
	public static final int INFINITE = 100;
	
	public AdjGragh(int arcnum,int nodenum){
		this.arcnum = arcnum;
		this.nodenum = nodenum;
//		ArcNode(int weight,int nextArcNo,int toNode)
		this.arcs.add(new ArcNode(1, 1, 1));
		this.arcs.add(new ArcNode(3, -1, 2));
		this.arcs.add(new ArcNode(2, 3, 2));
		this.arcs.add(new ArcNode(5, 4, 3));
		this.arcs.add(new ArcNode(1, -1, 4));
		this.arcs.add(new ArcNode(4, 6, 3));
		this.arcs.add(new ArcNode(2, -1, 4));
		this.arcs.add(new ArcNode(2, -1, 4));
		this.arcs.add(new ArcNode(3, -1, 5));
		this.arcs.add(new ArcNode(3, -1, 3));
//		 VNode(ArcNode firstArc,boolean isKnown)
		this.nodes.add(new VNode(0, false));
		this.nodes.add(new VNode(2, false));
		this.nodes.add(new VNode(5, false));
		this.nodes.add(new VNode(7, false));
		this.nodes.add(new VNode(8, false));
		this.nodes.add(new VNode(9, false));
	}
	
	public void print(){
		for(int i=0;i<this.nodenum;i++){
			int temp_arc_no = this.nodes.get(i).firstArcNo;
			System.out.print(NUM2EN[i]);
			while(this.arcs.get(temp_arc_no).nextArcNo != -1){
				System.out.print("->" + NUM2EN[this.arcs.get(temp_arc_no).toNode]);
				temp_arc_no = this.arcs.get(temp_arc_no).nextArcNo;
			}
			System.out.print("->" + NUM2EN[this.arcs.get(temp_arc_no).toNode]);
			System.out.println("");
		}
	}
	
	public void Dijkstra(){
		int[] dist = {0,INFINITE,INFINITE,INFINITE,INFINITE,INFINITE};
		boolean[] avai = {true,false,false,false,false,false};
		ArrayList<Integer> dones = new ArrayList<Integer>(); dones.add(0);
		
			int i=0;
			while(dones.size() != this.nodenum){
				
				if( avai[i] && (dones.contains(i)) && (dones.size() != this.nodenum)){
					int temp_arc_node = this.nodes.get(i).firstArcNo;
					int min_dist = INFINITE;
					int min_node = 0;
					do {
						int avai_node = this.arcs.get(temp_arc_node).toNode;
						if(!avai[avai_node])	avai[avai_node]=true;	//更新avai
						if(dist[avai_node] > this.arcs.get(temp_arc_node).weight + dist[i]){ //更新dist
							dist[avai_node] = this.arcs.get(temp_arc_node).weight + dist[i];						
						}
						for(int j=0;j<this.nodenum;j++){  //选出目前 要加入的顶点
							if(avai[j] && !(dones.contains(j)) && (dist[j] < min_dist)){
								min_dist = dist[j];
								min_node = j;
							}								
						}	
						temp_arc_node = this.arcs.get(temp_arc_node).nextArcNo;
					} while (temp_arc_node != -1);	
					dones.add(min_node);
					i = min_node;   //下一次从刚加入的顶点开始扩展殖民地
					//测试
					System.out.print("avai:	");
					for(int temp=0;temp<6;temp++){
						System.out.print(avai[temp]+"	");
					}
					System.out.println("");
					System.out.print("dist:	");
					for(int temp=0;temp<6;temp++){
						System.out.print(dist[temp]+"	");
					}
					System.out.println("");
					System.out.println("此时可到达的最小距离："+min_dist+"    加入这个顶点:"+NUM2EN[min_node]);
					System.out.print("此时加入最小路径的有（按加入顺序）:	");
					for(int temp=0;temp<dones.size();temp++){
						System.out.print(NUM2EN[dones.get(temp)]+"	");
					}
					System.out.println("\n==========================================");
					
				}
			}
	}
	public static void main(String[] args) {
		AdjGragh mygragh = new AdjGragh(10, 6);
		mygragh.print();
		mygragh.Dijkstra();
	}
}
