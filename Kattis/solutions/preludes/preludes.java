import java.util.Scanner;
import java.util.TreeMap;

public class Main {
  public static void main(String[] args) {
    TreeMap<String, String> translationKey = new TreeMap<>();
    translationKey.put("A#", "Bb");
    translationKey.put("Bb", "A#");
    translationKey.put("C#", "Db");
    translationKey.put("Db", "C#");
    translationKey.put("D#", "Eb");
    translationKey.put("Eb", "D#");
    translationKey.put("F#", "Gb");
    translationKey.put("Gb", "F#");
    translationKey.put("G#", "Ab");
    translationKey.put("Ab", "G#");

    Scanner scanner = new Scanner(System.in);
    int n = 1;

    while (scanner.hasNext()) {
      String key = scanner.next();
      String tonality = scanner.next();
      System.out.print("Case " + n + ": ");
      
      if (translationKey.containsKey(key)) {
        System.out.println(translationKey.get(key) + " " + tonality);
      } else {
        System.out.println("UNIQUE");
      }
      n++;
    }

    scanner.close();
  }
}