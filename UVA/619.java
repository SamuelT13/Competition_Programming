import java.util.*;
import java.lang.*;
import java.text.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        
        while (true){
            String s = cin.next(), temp = "";
            if (s.equals("*")) break;
            
            BigInteger sum = BigInteger.ZERO, m = BigInteger.ONE, res, n;
            
            if (!Character.isDigit(s.charAt(0)))
                for (int i = 0; i < s.length(); i++){
                    sum = sum.add(m.multiply(BigInteger.valueOf(Character.getNumericValue(s.charAt(s.length()-i-1)) 
                                                                - Character.getNumericValue('a') + 1)));
                    m = m.multiply(BigInteger.valueOf(26));
                }
            
            else{
                n = new BigInteger(s);
                sum = n;
                
                while (!n.equals(BigInteger.ZERO)){
                    n = n.add(BigInteger.valueOf(-1));
                    res = n.mod(BigInteger.valueOf(26));
                    n = n.divide(BigInteger.valueOf(26));
                    temp = temp + (char)(res.intValue() + 'a');
                }
                
                s = new StringBuffer(temp).reverse().toString();
            }
            
            String word = s;
            String num = NumberFormat.getNumberInstance(Locale.US).format(sum);
            
            System.out.printf("%-22s%s\n", s, num);
        }
    }
}
