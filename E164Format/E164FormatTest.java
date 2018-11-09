//**************************************************
//  
//    E164FormatTest Driver Class
//
//**************************************************


public class E164FormatTest{

    public static void main( String[] args ){

        E164Format format = new E164Format();
        format.setNumber("+1223222333");
        format.validateNumber();

    }
}
