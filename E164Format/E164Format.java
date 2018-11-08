//**************************************************
//  
//    E164Format Class
//
//**************************************************

// Declaration of Fraction class

public class E164Format{

    private String number;
    
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

    // setNumber Method
    public void validateNumber( String number ){

        this.number = number;
    
    }
    
   
    
}
