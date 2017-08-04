import java.util.*;
import java.lang.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        
        int test = cin.nextInt(), ind;
        String a, b, res;
        BigInteger x, y;
        
        while (test > 0){
            test--;
            a = cin.next();
            b = cin.next();
            a = new StringBuffer(a).reverse().toString();
            b = new StringBuffer(b).reverse().toString();
            
            x = new BigInteger(a);
            y = new BigInteger(b);
            
            res = new StringBuffer(x.add(y).toString()).reverse().toString();
            ind = 0;
            while (res.charAt(ind) == '0') ind++;
            res = res.substring(ind);
            System.out.println(res);
        }
    }
}
