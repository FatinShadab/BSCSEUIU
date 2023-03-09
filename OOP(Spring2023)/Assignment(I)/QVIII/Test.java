class Book{
    void description(){
        // ; added to fix the error
        System.out.println("Books are awesome");
    }

    void putPageMarker(int pageNo){
        System.out.println("To avoid error");
    }
}

class PaperBackBook extends Book{
    // added to provide the desire output
    @Override
    void description(){
        System.out.println("Paperback books are good for your eyes!");
    }

    @Override
    void putPageMarker(int pageNo){
        System.out.println("Page marker was " + 
        "put on page no: " + pageNo);
    }
}

// need to do the Test class public
public class Test{
    public static void main(String[] args){
        Book book1, book2;

        book1 = new Book();
        book2 = new PaperBackBook();

        book1.description();
        book2.description();
        // need to pass a int to avoid error
        book2.putPageMarker(50);
    }
}