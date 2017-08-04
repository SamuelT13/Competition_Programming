import java.util.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int test = cin.nextInt(), c = 0;
        BigInteger ten = BigInteger.valueOf(10);
        
        for (int t = 0; t < test; t++){
            if (t > 0) System.out.println("");
            int size = cin.nextInt();          
            BigInteger A, B;
			String x = new String(""), y = new String("");
			int d1, d2;
            
            while (size-- > 0){
                d1 = cin.nextInt();
                d2 = cin.nextInt();
                x += d1;
                y += d2;
            }
            A = new BigInteger(x);
            B = new BigInteger(y);
            
            System.out.println(A.add(B));
        }
    }
}
