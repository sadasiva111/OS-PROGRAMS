import java.io.*;

class Demo2{
    public static void main(String[] args) throws IOException {
        BufferedReader reader1 = new BufferedReader(new FileReader("c://GC//demo1.txt"));
        BufferedReader reader2 = new BufferedReader(new FileReader("c://GC//demo2.txt"));
        String s1,s2;
        while((s1=reader1.readLine())!=null&& (s2=reader2.readLine())!=null) {
            if (s1.equals(s2)) {
                System.out.println("Line is Same");

            }
            else{
                System.out.println(s1 + "\t" +s2);
            }
        }
    }
}
