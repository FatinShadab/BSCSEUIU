/*
    Task : Modify the following code so that it runs without error and write the output of the following program
    ====================================================================
    
    public class Test{
        int TestA(){
            throw new Exception("Exception has been thrown from TestA");
            System.out.println("Don't forget me!");

            return 0;
        }

        void TestB(){
            int a = TestA();

            if (a == 0){
                System.out.println("Exception in TestB: a is zero");
            }else{
                System.out.println("You should figure out the value of a: " + a);
                throw new Exception("Exception from else clause in TestB");
            }

            return;
        }

        boolean TestC(boolean val){
            if (val == false){
                throw new Exception("Exception in TestC");
            }

            return false;
        }

        public static void main(String[] args){
            try{
                TestC(false);
            }
            catch(Exception e){
                System.out.println(e);
                
                try{
                    TestB();
                }
                catch(Exception e1){
                    System.out.println(e1);
                }
            }
        }
    }
*/

// *** Need to make every method static method
// *** Added "throws Exception" in func "TestB", "TestC"

public class Test{
    
    static int TestA() throws Exception{
        System.out.println("Don't forget me!");

        return 0;
    }

    static void TestB() throws Exception{
        int a = TestA();

        if (a == 0){
            System.out.println("Exception in TestB: a is zero");
        }else{
            System.out.println("You should figure out the value of a: " + a);
            throw new Exception("Exception from else clause in TestB");
        }

        return;
    }

    static boolean TestC(boolean val) throws Exception{
        if (val == false){
            throw new Exception("Exception in TestC");
        }

        return false;
    }

    public static void main(String[] args){
        try{
            TestC(false);
        }
        catch(Exception e){
            System.out.println(e);
            
            try{
                TestB();
            }
            catch(Exception e1){
                System.out.println(e1);
            }
        }
    }
}