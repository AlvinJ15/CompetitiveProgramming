import java.util.*;
class owl{
    public static void main(String[] args) {
          int num;
              Scanner sc = new Scanner(System.in);
                  String in = sc.nextLine();
                      while(!in.equals("END")){
                              num =  Integer.parseInt(in);
                                    System.out.println(getNumLess(num));
                                          in = sc.nextLine();
                                              }
                        }

      public static int getNumLess(int val){
            int i   = 10 ;
                while(val%i==0){
                        i*=10;
                            }
                    return val - i/10;
                      }
}
