import java.util.*;

public class horror {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int h = scanner.nextInt();
        int l = scanner.nextInt();

        int[] scores = new int[n];
        Arrays.fill(scores, Integer.MAX_VALUE);  // Use Integer.MAX_VALUE instead of 1e9

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < h; i++) {
            int id = scanner.nextInt();
            queue.add(id);
            scores[id] = 0;
        }

        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            adjList.add(new ArrayList<>());
        }
        
        for (int i = 0; i < l; i++) {
            int first = scanner.nextInt();
            int second = scanner.nextInt();
            adjList.get(first).add(second);
            adjList.get(second).add(first);
        }

        while (!queue.isEmpty()) {
            int curr = queue.poll();

            for (int neighbor : adjList.get(curr)) {
                if (scores[neighbor] > scores[curr] + 1) {
                    scores[neighbor] = scores[curr] + 1;
                    queue.add(neighbor);
                }
            }
        }

        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (scores[i] > scores[maxIndex]) {
                maxIndex = i;
            }
        }

        System.out.println(maxIndex);

        scanner.close();
    }
}
