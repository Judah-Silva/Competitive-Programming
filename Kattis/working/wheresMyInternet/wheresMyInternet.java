import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Stack;

public class wheresmyinternet {
    static boolean[] connected;

    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] firstLine = reader.readLine().split(" ");
            int houses = Integer.parseInt(firstLine[0]);
            int edges = Integer.parseInt(firstLine[1]);

            connected = new boolean[houses + 1];
            ArrayList<ArrayList<Integer>> graph = new ArrayList<>(houses + 1);

            for (int i = 0; i <= houses; i++) graph.add(new ArrayList<>());

            for (int i = 0; i < edges; i++) {
                String[] edge = reader.readLine().split(" ");
                int from = Integer.parseInt(edge[0]);
                int to = Integer.parseInt(edge[1]);
                graph.get(from).add(to);
                graph.get(to).add(from);
            }

            Stack<Integer> stack = new Stack<>();
            stack.push(1);

            while (!stack.isEmpty()) {
                int curr = stack.pop();

                if (connected[curr]) continue;
                connected[curr] = true;

                for (int neighbor : graph.get(curr)) {
                    stack.push(neighbor);
                }
            }

            boolean isConnected = true;
            for (int i = 1; i <= houses; i++) {
                if (!connected[i]) {
                    System.out.println(i);
                    isConnected = false;
                }
            }

            if (isConnected) System.out.println("Connected");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
