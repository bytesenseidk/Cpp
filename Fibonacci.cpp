class FibonacciClass {
public:
    static int basicFibonacci(int num) {
        int a = 0; int b = 1; int c = a + b;
        for (int i = 0; i < num; i++) {
            a = b;
            b = c;
            c = a + b;
        }
        return a;
    }

    static int recursiveFibonacci(int num) {
        if (num <= 1) {
            return num;
        }
        return recursiveFibonacci(num - 1) + recursiveFibonacci(num - 2);
    }
};