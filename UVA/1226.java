import java.util.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        
        int test = cin.nextInt();
        BigInteger P, N;
        
        while (test-- != 0){
            N = cin.nextBigInteger();
            P = cin.nextBigInteger();
            System.out.println(P.mod(N).toString());
        }
    }
}
