import java.lang.Math;

class MathPractice {
    public static void power_table(int n) {
        // Write a program that display the following table
        //a^1    a^2     a^3
        //1      1       1
        //2      4       8
        //3      9       27
        
        for (int i = 1; i <= n; i++) {
            System.out.printf("a^%d\t", i);
        }
        System.out.println("");

        for (int i = 1; i <= n; i++) { // actual line
            for (int p = 1; p <= n; p++) {
                System.out.printf("%.0f\t", Math.pow(i, p));
            }
            System.out.println("");
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        power_table(5);
    }
}