import java.util.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        BigInteger limit = BigInteger.valueOf(2147483647);

        while (cin.hasNext()){
            String line = cin.nextLine();
            String [] words = line.split("\\s+");
            
            int ind = 0;
            if (words[0].equals("")) ind = 1;
            
            String x = words[ind], op = words[ind+1], y = words[ind+2];
            BigInteger A = new BigInteger(x), B = new BigInteger(y);
            BigInteger res = BigInteger.ZERO;
            
            if (op.equals("+")) res = A.add(B);
            
            else res = A.multiply(B);
            
            System.out.println(line);
            if (A.compareTo(limit) == 1) System.out.println("first number too big");
            if (B.compareTo(limit) == 1) System.out.println("second number too big");
            if (res.compareTo(limit) == 1) System.out.println("result too big");
        }
    }
}
