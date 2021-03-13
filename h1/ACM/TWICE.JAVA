public class TWICE{
	static int[] numero= new int[20];
	static int[]  hash= new int[10];
	static int N;
	public static void llenarHash(int index){
  		for(int i=0;i<10;i++)
  			hash[i]=0;
  		for(int i=0;i<index;i++)
  		  hash[numero[i]]++;
	}
	public static void llenarNumero(int index){
		  for(int i=index+1;i<N;i++)
		    for(int j=9;j>=0;j--)
		      if(hash[j]<2){
		        hash[j]++;
		        numero[i]=j;
		        break;
		  }
	}
	public static void restar(int index){
		  llenarHash(index);
		  int var=numero[index]-1;
		  int i;
		  for(i=var;i>=0;i--){
		    if(hash[i]<2){
		      numero[index]=i;
		      hash[i]++;
		      llenarNumero(index);
		      return;
		    }
		  }
		  if(i=-1){
		    return restar(index-1);
		  }
	}
	public static void main(String args[]){
		String palabra;
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			palabra=sc.next();
			for(int i=0;i<palabra.length();i++)
				numero[i]=palabra.charAt(i)-'0';
			N=palabra.length();
			for(int i =0;i<palabra.size();i++){
			    if(hash[numero[i]]<2){
			      hash[numero[i]]++;
			    }
			    else{
			      restar(i);
			      break;
			    }
  			}
  			for(int i=0;i<N;i++){
			    if(i==0 &&numero[0]==0)
			      continue;
			    System.out.print(numero[i]);
			  	}
			  System.out.println();
			  


		}

	}

}