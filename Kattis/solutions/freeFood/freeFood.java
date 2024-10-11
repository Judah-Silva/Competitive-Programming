import java.util.Scanner;
import java.util.TreeSet;

public class Main {
  public static void main(String[] args) {
    TreeSet<Integer> set = new TreeSet<>();
    Scanner scanner = new Scanner(System.in);
    
    int n = scanner.nextInt();
    int days1, days2;
    
    for (int i = 0; i < n; i++) {
      days1 = scanner.nextInt();
      days2 = scanner.nextInt();
      for (int j = days1; j <= days2; j++) {
        set.add(j);
      }
    }
    
    System.out.println(set.size());
    scanner.close();
  }
}
