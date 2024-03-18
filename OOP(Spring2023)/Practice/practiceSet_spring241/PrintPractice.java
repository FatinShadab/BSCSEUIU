class PrintPractice {
    private static void problem_one() {
        // WAP that displays Welcome to Java, Welcome to Computer Science, and
        // Programming is fun at three different lines

        System.out.println("Welcome to Java\nWelcome to Computer Science\nProgramming is fun");
    }

    private static void problem_two(int n) {
        // Write a program that displays Welcome to Java five times in five lines
        for (int i = 1; i <= n; i++) {
            System.out.println("Welcome to Java");
        }
    }

    public static void main(String[] args) {
        problem_one();
        problem_two(10);
    }
}