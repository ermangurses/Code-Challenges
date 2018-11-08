//**************************************************
//  
//    E164Format Class
//
//**************************************************

// Declaration of Fraction class

public class E164Format{

    private String number;
    private String regex = "^\+?[1-9]\d{1,14}$"; 
    // Default constructor 
    public E164Format(){
        this("");
    }
    
    // Overloaded constructor
    public E164Format( String number ){
       
        this(number);

    }
    
    // setNumber Method
    public void setNumber( String number ){

        this.number = number;

    }

    // validateNumber Method
    private boolean validateNumber(){

        return this.number.matches(regex);
    }
    
   
    
}
