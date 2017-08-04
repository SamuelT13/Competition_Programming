import java.util.*;
import java.math.*;

class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()){
            BigDecimal R = cin.nextBigDecimal();
            int n = cin.nextInt();
            
            String s = R.pow(n).toPlainString();
            if (s.length() > 1 && s.charAt(0) == '0' && s.charAt(1) == '.') s = s.substring(1);
            
            int ind = s.length()-1;
            if (s.indexOf('.') != -1){
                while (s.charAt(ind) == '0') ind--;
                if (s.charAt(ind) == '.') ind--;
            }
            
            s = s.substring(0, ind+1);
            if (s.equals("")) s = "0";
            System.out.println(s);
        }
    }
}
