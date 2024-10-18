import java.util.*;

public class mathHomework {
  public static void main(String args[]) {
    Scanner scan = new Scanner(System.in);
    int bird = scan.nextInt();
    int dog = scan.nextInt();
    int cat = scan.nextInt();
    int legs = scan.nextInt();

    boolean sol = false;
    for (int i = 0; i <= 250; i++) {
      for (int j = 0; j <= 250; j++) {
        for (int k = 0; k <= 250; k++) {
          if (((i * bird) + (j * dog) + (k * cat)) == legs) {
            System.out.println(i + " " + j + " " + k);
            sol = true;
          }
        }
      }
    }

    if (!sol) {
      System.out.println("impossible");
    }
  }
}
