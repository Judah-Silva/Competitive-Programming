import java.util.*;

public class grid {

    static boolean inRange(int[][] grid, int row, int col) {
        return !(row < 0 || col < 0 || row >= grid.length || col >= grid[0].length);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int rows = scanner.nextInt();
        int cols = scanner.nextInt();

        int[][] grid = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            String line = scanner.next();
            for (int j = 0; j < cols; j++) {
                grid[i][j] = line.charAt(j) - '0';
            }
        }

        int[][] dist = new int[rows][cols];
        for (int[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0, 0});
        dist[0][0] = 0;

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int row = current[0];
            int col = current[1];
            int val = grid[row][col];

            if (inRange(grid, row - val, col) && dist[row][col] + 1 < dist[row - val][col]) {
                dist[row - val][col] = dist[row][col] + 1;
                queue.add(new int[]{row - val, col});
            }
            if (inRange(grid, row + val, col) && dist[row][col] + 1 < dist[row + val][col]) {
                dist[row + val][col] = dist[row][col] + 1;
                queue.add(new int[]{row + val, col});
            }
            if (inRange(grid, row, col - val) && dist[row][col] + 1 < dist[row][col - val]) {
                dist[row][col - val] = dist[row][col] + 1;
                queue.add(new int[]{row, col - val});
            }
            if (inRange(grid, row, col + val) && dist[row][col] + 1 < dist[row][col + val]) {
                dist[row][col + val] = dist[row][col] + 1;
                queue.add(new int[]{row, col + val});
            }
        }

        int result = dist[rows - 1][cols - 1];

        if (result == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(result);
        }

        scanner.close();
    }
}