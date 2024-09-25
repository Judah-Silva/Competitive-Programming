import java.util.*;

class eenyMeeny {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String line = s.nextLine();
    String[] rhymes = line.split(" ");
    int numKids = s.nextInt();
    s.nextLine();
    
    Queue<String> queue = new LinkedList<>();
    for (int i = 0; i < numKids; i++) {
      String kid = s.nextLine();
      queue.add(kid);
    }
    
    ArrayList<String> team1 = new ArrayList<>();
    ArrayList<String> team2 = new ArrayList<>();
    boolean team = true;
    while (!queue.isEmpty()) {
      for (int i = 0; i < rhymes.length - 1; i++) {
        String kid = queue.remove();
        queue.add(kid);
      }
      if (team) {
        team1.add(queue.remove());
      } else {
        team2.add(queue.remove());
      }
      team = !team;
    }
    
    System.out.println(team1.size());
    for (String kid : team1) {
      System.out.println(kid);
    }
    
    System.out.println(team2.size());
    for (String kid : team2) {
      System.out.println(kid);
    }
        
  }
}
