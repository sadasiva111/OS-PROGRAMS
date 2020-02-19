import java.util.Scanner;

class Person{
    int time,deadline,id;
    Person(int id,int time,int deadline){
        this.id=id;
        this.time=time;
        this.deadline=deadline;
    }
}
public class ShortDeadline {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);

        Person []p={new Person(0,4,3),new Person(1,3,5),new Person(2,2,3),
                    new Person(3,6,7),new Person(4,5,4)};

        int count=check(p);
        sort(p);
        int duration=0;
        for(int i=count;i<p.length;i++){
            duration+=p[i].time;
            System.out.println("Process "+p[i].id+" is completed at "+duration+" seconds");
        }

    }
    static int check(Person[]p){
        int count=0;
        for (int i = 0; i <p.length; i++) {
            if(!(p[i].time<=p[i].deadline)){
                System.out.println("the  task " +i+" cant be performed since burst time is greater than deadline");
                p[i].time=0;
                p[i].deadline=0;
                count++;
            }
        }
       
        return count;
    }
    static void sort(Person[]p){
        for (int i = 0; i <p.length-1 ; i++) {
            for (int j = 0; j <p.length-i-1 ; j++) {
                if(p[j].deadline>p[j+1].deadline){
                    int temp=p[j].deadline;
                    p[j].deadline=p[j+1].deadline;
                    p[j+1].deadline=temp;
                    temp=p[j].time;
                    p[j].time=p[j+1].time;
                    p[j+1].time=temp;
                    temp=p[j].id;
                    p[j].id=p[j+1].id;
                    p[j+1].id=temp;
                }
            }
        }


    }
}
