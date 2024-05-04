import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int ordersToday = scan.nextInt();
    scan.nextLine();

    while (ordersToday != 0) {
      TreeMap<String, TreeSet<String>> map = new TreeMap<>();
      for (int i = 0; i < ordersToday; i++) {
        String line = scan.nextLine();
        String[] words = line.split(" ");
        for (int j = 1; j < words.length; j++) {
          if (!map.containsKey(words[j])) {
            map.put(words[j], new TreeSet<String>());
          }
          map.get(words[j]).add(words[0]);
        }
      }

      for (Map.Entry<String, TreeSet<String>> entry : map.entrySet()) {
        System.out.print(entry.getKey());
        for (String s : entry.getValue()) {
          System.out.print("  " + s);
        }
        System.out.println();
      }

      System.out.println();
      ordersToday = scan.nextInt();
      scan.nextLine();
    }
  }
}
