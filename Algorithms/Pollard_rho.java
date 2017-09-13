import java.util.*;
import java.math.*;

public class Main{
    static List<BigInteger> list = new ArrayList<BigInteger>();
    static List<Integer> prime = new ArrayList<Integer>();
    
    public static void p(){
        boolean [] pr = new boolean[101];
        
        for (int i = 0; i <= 100; i++) pr[i] = false;
        pr[0] = true; pr[1] = true;
        for (int i = 2; i*i <= 100; i++)
            if (pr[i] == false)
                for (int j = i*i; j <= 100; j += i) pr[j] = true;

        for (int i = 2; i <= 100; i++)
            if (pr[i] == false) prime.add(i);
    }
    
    public static void man_fact(BigInteger z){
        int n = z.intValue();
        for (int i = 0; prime.get(i) <= n; i++)
            while (n % prime.get(i) == 0){
                list.add(BigInteger.valueOf(prime.get(i)));
                n /= prime.get(i);
            }
        
        if (n > 1) list.add(BigInteger.valueOf(n));
    }
    
    public static BigInteger mulmod(BigInteger a, BigInteger b, BigInteger c){
        BigInteger x = BigInteger.ZERO, y = a.mod(c);
        
        while (b.compareTo(BigInteger.ZERO) == 1){
            if ((b.mod(BigInteger.valueOf(2))).equals(BigInteger.valueOf(1)))
                x = (x.add(y)).mod(c);
            y = ((y.multiply(BigInteger.valueOf(2)))).mod(c);
            b = b.divide(BigInteger.valueOf(2));
        }
        
        return x.mod(c);
    }
    
    public static void pollard_rho(BigInteger n){
        int i = 0, k = 2;
        BigInteger x, y, d, m;
        x = BigInteger.valueOf(3); y = BigInteger.valueOf(3);
        
        while (true){
            i++;
            x = (mulmod(x, x, n).add(n.add(BigInteger.valueOf(-1)))).mod(n);
            m = (y.add(x.multiply(BigInteger.valueOf(-1)))).abs();
            d = m.gcd(n);
            
            if (d.compareTo(BigInteger.valueOf(1)) != 0 && d.compareTo(n) != 0){
                m = n.divide(d);
                
                if (d.isProbablePrime(95)) list.add(d);
                else if (d.compareTo(BigInteger.valueOf(100)) == -1) man_fact(d);
                else pollard_rho(d);
                
                if (m.isProbablePrime(95)) list.add(m);
                else if (m.compareTo(BigInteger.valueOf(100)) == -1) man_fact(m);
                else pollard_rho(m);
                
                return;
            }
            if (i == k){
                y = x;
                k *= 2;
            }
        }
    }
    
    public static void main(String [] args){
        Scanner cin = new Scanner(System.in);
        int total = cin.nextInt();
        BigInteger num, ans;
        
        p();
        
        for (int i = 0; i < total; i++){
            num = cin.nextBigInteger();
            
            if (num.isProbablePrime(95)) System.out.println(num);
            else{
                list.clear();
                pollard_rho(num);
                Collections.sort(list);
                for (int ind = 0; ind < list.size(); ind++){
                    if (ind > 0) System.out.print(" ");
                    System.out.print(list.get(ind));
                } System.out.println();
            }
        }
        
    }
}
