public class LinearProbing {
    public static void main(String[] args) {
        int []a={30,23,11,24,13};
        int n=a.length;
        int []table=new int[n];
        for (int i = 0; i <n ; i++) {
            table[i]=0;
        }
        hashing(a,table);
        for (int i = 0; i <n ; i++) {
            System.out.println(table[i]);
        }
    }
    static void hashing(int []a,int[]table){
        for (int i=0;i<a.length;i++){
            int val=a[i]%10;
            if(table[val]==0){
                table[val]=a[i];
            }
            else {
                for (int j = 0; j <a.length ; j++) {
                    if(table[j]==0){
                        table[j]=a[i];
                    }
                }

            }
        }
    }
}
