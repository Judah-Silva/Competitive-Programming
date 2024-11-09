import java.util.*;

public class reachableroads {
  static ArrayList<Integer> visited;

  public static void dfs(ArrayList<ArrayList<Integer>> graph, int curr) {
    if (visited.get(curr) == 1) return;
    visited.set(curr, 1);
    for (int neighbor : graph.get(curr)) dfs(graph, neighbor);
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();

    while (n > 0) {
      int v = scanner.nextInt();
      int e = scanner.nextInt();

      ArrayList<ArrayList<Integer>> graph = new ArrayList<>(v);
      for (int i = 0; i < v; i++) graph.add(new ArrayList<>());

      for (int i = 0; i < e; i++) {
        int from = scanner.nextInt();
        int to = scanner.nextInt();
        graph.get(from).add(to);
        graph.get(to).add(from);
      }

      int cc = 0;
      visited = new ArrayList<>();
      for (int i = 0; i < v; i++) visited.add(0);

      for (int i = 0; i < v; i++) {
        if (visited.get(i) == 0) {
          cc++;
          dfs(graph, i);
        }
      }

      System.out.println(cc - 1);
      n--;
    }

    scanner.close();
  }
}
