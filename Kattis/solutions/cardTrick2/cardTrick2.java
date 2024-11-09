import java.util.*;

public class cardtrick2 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();

    ArrayList<LinkedList<Integer>> res = new ArrayList<>();
    for (int i = 1; i <= 13; i++) {
      LinkedList<Integer> list = new LinkedList<>();
      for (int j = i; j > 0; j--) {
        list.addFirst(j);
        for (int k = 0; k < j; k++) {
          int temp = list.removeLast();
          list.addFirst(temp);
        }
      }
      res.add(list);
    }

    for (int i = 0; i < n; i++) {
      int query = scanner.nextInt();
      for (int num : res.get(query - 1)) {
        System.out.print(num + " ");
      }
      System.out.println();
    }

    scanner.close();
  }
}
