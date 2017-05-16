import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
 
public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> vet = new ArrayList<Integer>();
        while(sc.hasNext()) {
            int num = sc.nextInt();
            if(num == -999999) {
                BigInteger max = BigInteger.valueOf(num);
                BigInteger prod = BigInteger.valueOf(0);
 
                for(int i = 0; i < vet.size(); i++) {
                    prod = BigInteger.valueOf(1);
                    for(int j = i; j < vet.size(); j++) {
                        prod = prod.multiply(BigInteger.valueOf(vet.get(j)));
                        if(prod.compareTo(max) == 1)
                            max = prod;
                    }
                }
                System.out.println(max.toString());
                vet.clear();
            }
            else
                vet.add(num);
        }
    }
}