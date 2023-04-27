/*
Suppose you have a file “id.txt” that contains the ids of multiple UIU students. Write a java code
to write the odd ids in the id.txt file to another file called “odd.txt” and the even ids in the id.txt
file to another file called “even.txt”. Check the following example for clarification:
*/

import java.io.*;

public class IDR{
    public static void main(String[] args){
        File srcFile = new File("id.txt");
        File oddFile = new File("odd.txt");
        File evenFile = new File("even.txt");

        try{
            String id;
            
            BufferedReader reader = new BufferedReader(new FileReader(srcFile));
            BufferedWriter oddWriter = new BufferedWriter(new FileWriter(oddFile));
            BufferedWriter evenWriter = new BufferedWriter(new FileWriter(evenFile));
            
            while ((id = reader.readLine()) != null){
                //System.out.println(id);

                int last_digit = id.toCharArray()[8]-'0';

                if (last_digit%2 == 0){
                    evenWriter.write(id + '\n');
                }else{
                    oddWriter.write(id + '\n');
                }
            }

            reader.close();
            oddWriter.close();
            evenWriter.close();
        }
        catch (IOException e){
            System.out.println(e);
        }
    }
}