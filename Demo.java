import java.io.*;

class Demo{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("c://GC//demo.txt"));
        String s;
        String keyword ="this";
        while((s=br.readLine())!=null)
            if(s.contains(keyword))
                System.out.println(s);
    }
}
