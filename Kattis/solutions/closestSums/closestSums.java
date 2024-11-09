import java.util.*;

public class closestsums {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int n, caseNum = 1;

    while (scan.hasNext()) {
      n = scan.nextInt();
      int m;
      ArrayList<Integer> input = new ArrayList<>();
      for (int i = 0; i < n; i++) {
        input.add(scan.nextInt());
      }

      Collections.sort(input);

      System.out.println("Case " + caseNum++ + ":");

      m = scan.nextInt();
      for (int i = 0; i < m; i++) {
        int query = scan.nextInt(), closestSum = -1000000000;

        for (int j = 0; j < n - 1; j++) {
          for (int k = j + 1; k < n; k++) {
            if (Math.abs(input.get(j) + input.get(k) - query) < Math.abs(closestSum - query)) {
              closestSum = input.get(j) + input.get(k);
            }
          }
        }

        System.out.println("Closest sum to " + query + " is " + closestSum + ".");
      }
    }

    scan.close();
  }
}