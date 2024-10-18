import java.util.*;

public class warehouse {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int t = scanner.nextInt();

    while (t > 0) {
      int n = scanner.nextInt();

      Map<String, Integer> frequency = new HashMap<>();
      for (int i = 0; i < n; i++) {
        String toy = scanner.next();
        int num = scanner.nextInt();

        frequency.put(toy, frequency.getOrDefault(toy, 0) + num);
      }

      Map<Integer, Set<String>> res = new TreeMap<>(Collections.reverseOrder());
      for (Map.Entry<String, Integer> entry : frequency.entrySet()) {
        int count = entry.getValue();
        String toy = entry.getKey();

        if (!res.containsKey(count)) {
          res.put(count, new TreeSet<>());
        }

        res.get(count).add(toy);
      }

      System.out.println(frequency.size());
      for (Map.Entry<Integer, Set<String>> entry : res.entrySet()) {
        for (String toy : entry.getValue()) {
          System.out.println(toy + " " + entry.getKey());
        }
      }

      t--;
    }

    scanner.close();
  }
}