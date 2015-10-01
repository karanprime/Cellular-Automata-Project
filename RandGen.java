import java.io.*;
import java.util.*;

public class RandGen  {
    static int index;
    static int ruleset[] = {0,1,1,1,1,0,0,0};
    public  static void main(String[] args) throws IOException{
          
        System.out.println("Enter seed");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int seed = Integer.parseInt(br.readLine());
      /*for(int x = 0; x < 2000; x++) {
        
        
        System.out.println("" + x + "\t" + ans);//*/
        int ans = randGen(seed);
        System.out.println("Using rule 30, with seed " + seed + " your output is: "+ ans);


         }

  public static int randGen(int seed) {
    int cur[] = {0,0,0,0,0,1,0,0,0,0};
    int ran[] = {0,0,0,0,0,0,0,0,0,0};
    int next[] = {0,0,0,0,0,0,0,0,0,0};
        int left, right, it;
        int iterations;
        index = 0;
        //int seed;
        int ans;
        iterations = 0;
        ans = 0;
        left =0;
        right = 0;
        it = 0;
        boolean chk = true;
        int chk2 = 0;

         while(iterations < seed + 10) {
        for (int i = 0; i < 10; i++) {
       
       left   = cur[mod((i-1),10)];
       it     = cur[i];
       right  = cur[mod((i+1),10)];
       next[i] = rules(left, it, right);
       //System.out.print(next[i]);
       //tSystem.out.print (next[i]);
    }
    cur = next;
    if(iterations >= seed) {
      if(chk) {
        chk2 = iterations;
        chk = false;
      }
      ran[iterations-chk2] = cur[5];
      //System.out.println(""+ (iterations-chk2) + " " + ran[iterations-chk2]);
    }
    iterations++;

    } 
        //ans = (512 * cur[9] + 256* cur[8] +128* cur[7] + 64* cur[6] +32* cur[5] +16* cur[4] +8* cur[3] +4* cur[2] +2* cur[1] +1* cur[0] );
        ans = (512 * ran[9] + 256* ran[8] +128* ran[7] + 64* ran[6] +32* ran[5] +16* ran[4] +8* ran[3] +4* ran[2] +2* ran[1] +1* ran[0] );
        
        return ans;
       // System.out.println("Using rule 30, with seed " + seed + " your output is: "+ ans);
  } 

  public static int rules(int a, int b, int c) {
  
    index = a*4+b*2+c*1;
    return ruleset[index];
  }
  public static int mod (int a, int b)
  {
    int d=a%b;
    if (d<0)
      d=d+b;

    return(d);

  }

  public static int[] convertToBinary(int dec) {
      int[] bits = new int[8];
      //System.out.println(dec+":");
      for (int i = 7; i >= 0; i--) {
          bits[i] = ((dec & (1 << i)) != 0)?1:0;
          //System.out.print(bits[i]);
      }
      //System.out.println("");  
      return bits;
    }

    public static int[] convertToBinary2(int dec) {
      int[] bits = new int[10];
      //System.out.println(dec+":");
      for (int i = 9; i >= 0; i--) {
          bits[i] = ((dec & (1 << i)) != 0)?1:0;
          //System.out.print(bits[i]);
      }
      //System.out.println("");  
      return bits;
    }

}