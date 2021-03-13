import java.util.*;
public class pruenita{
  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    while(true){
    int A=sc.nextInt();
    int B= sc.nextInt();
    int X= sc.nextInt();
    String p;
    int r=0;
    for(int i=A;i<=B;i++){
      p=""+i;
      if(p.indexOf(""+X)!=-1)
        r++;
    }
    System.out.println(r);}
  }
}
