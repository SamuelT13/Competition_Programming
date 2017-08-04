import java.util.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        BigInteger res = BigInteger.valueOf(0);
        
        while (true){
            BigInteger num = cin.nextBigInteger();
            
            if (num.equals(BigInteger.ZERO)) break;
            
            res = res.add(num);
        }        
        
        System.out.println(res);
    }
}
