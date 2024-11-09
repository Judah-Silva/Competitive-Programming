/** THIS CODE IS TRANSLATED FROM C++ USING CHATGPT */
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class moneymatters {
  static List<Integer> colors;
  static int color = 1;

  public static void dfs(List<List<Integer>> graph, int curr) {
    colors.set(curr, color);
    for (int friend_ : graph.get(curr)) {
      if (colors.get(friend_) == 0) {
        dfs(graph, friend_);
      }
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int people = scanner.nextInt();
    int friendships = scanner.nextInt();

    // Initialize colors and owed lists
    colors = new ArrayList<>();
    List<Integer> owed = new ArrayList<>();
    for (int i = 0; i < people; i++) {
      colors.add(0); // initialize with zero for each person
      owed.add(scanner.nextInt());
    }

    // Initialize graph
    List<List<Integer>> graph = new ArrayList<>();
    for (int i = 0; i < people; i++) {
      graph.add(new ArrayList<>());
    }
    for (int i = 0; i < friendships; i++) {
      int first = scanner.nextInt();
      int second = scanner.nextInt();
      graph.get(first).add(second);
      graph.get(second).add(first);
    }

    // DFS for each uncolored person
    for (int i = 0; i < people; i++) {
      if (colors.get(i) == 0) {
        color++;
        dfs(graph, i);
      }
    }

    // Calculate sums for each component
    List<Integer> sums = new ArrayList<>();
    for (int i = 0; i <= color; i++) {
      sums.add(0);
    }
    for (int i = 0; i < colors.size(); i++) {
      sums.set(colors.get(i), sums.get(colors.get(i)) + owed.get(i));
    }

    // Check if all sums are zero
    for (int sum : sums) {
      if (sum != 0) {
        System.out.println("IMPOSSIBLE");
        scanner.close();
        return;
      }
    }

    System.out.println("POSSIBLE");
    scanner.close();
  }
}
