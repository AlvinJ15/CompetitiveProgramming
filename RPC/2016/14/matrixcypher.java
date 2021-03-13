import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;
public class matrixcypher {
	 static class FastReader
	    {
	        BufferedReader br;
	        StringTokenizer st;
	 
	        public FastReader()
	        {
	            br = new BufferedReader(new
	                     InputStreamReader(System.in));
	        }
	 
	        String next()
	        {
	            while (st == null || !st.hasMoreElements())
	            {
	                try
	                {
	                    st = new StringTokenizer(br.readLine());
	                }
	                catch (IOException  e)
	                {
	                    e.printStackTrace();
	                }
	            }
	            return st.nextToken();
	        }
	 
	        int nextInt()
	        {
	            return Integer.parseInt(next());
	        }
	 
	        long nextLong()
	        {
	            return Long.parseLong(next());
	        }
	 
	        double nextDouble()
	        {
	            return Double.parseDouble(next());
	        }
	 
	        String nextLine()
	        {
	            String str = "";
	            try
	            {
	                str = br.readLine();
	            }
	            catch (IOException e)
	            {
	                e.printStackTrace();
	            }
	            return str;
	        }
	    }
	public static void main(String[] args) {
		FastReader s=new FastReader();
		BigInteger [][] M = new BigInteger[2][2];
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				String a = s.next();
				M[i][j]= new BigInteger(a);
			}
		}
		String resp="";
		while(!isIdentity(M)){
			if(isT(M)){
				M[0][0]=M[0][0].subtract(M[0][1]); 
				M[1][0]=M[1][0].subtract(M[1][1]);
				resp="0"+resp;
			}
			else{
				M[0][1]=M[0][1].subtract(M[0][0]); 
				M[1][1]=M[1][1].subtract(M[1][0]);
				resp="1"+resp;
			}
		}
		System.out.println(resp);
	}
	public static boolean isT(BigInteger A[][]){
		if(A[0][0].compareTo(A[0][1])!=0)
			return A[0][0].compareTo(A[0][1])==1;
		return A[1][0].compareTo(A[1][1])==1;
	}
	public static boolean isIdentity(BigInteger A[][]){
		return A[0][0].compareTo(BigInteger.ONE)==0&&A[1][1].compareTo(BigInteger.ONE)==0&&A[0][1].compareTo(BigInteger.ZERO)==0&&A[1][0].compareTo(BigInteger.ZERO)==0;
			
	}
}
