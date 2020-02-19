import java.util.Scanner;

public class CircularArray {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        System.out.println("Enter the size of array");
        int n=in.nextInt();
        int []a=new int[n];
        System.out.println("Enter the elements of array");
        for (int i = 0; i <n ; i++) {
            a[i]=in.nextInt();
        }
        int first=0,last=n-1;
        System.out.println("Enter the index of array where the cycle starts");
        int index=in.nextInt();
        System.out.println("array elemets are");
        show(a,first,last,index);
    }
    static void show(int []a,int first,int last,int index){
        System.out.println(a[index]);
       if(index>first&&index<last){
           for (int i = index+1; i <=last ; i++) {
               System.out.println(a[i]);
           }
           for (int i = first; i <index ; i++) {
               System.out.println(a[i]);
           }
       }


    }
}
