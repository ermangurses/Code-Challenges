/** 
 * E164FormatTest is the driver class that tests E164Format implementation
 * @author Erman Gurses
 * @version 1.0
 * @since 2018-11-18
 */

public class E164FormatTest {

    public static void main(String[] args) {
        
        E164Format formatNumber = new E164Format();
        
        formatNumber.setNumber("216562255");
        System.out.println(formatNumber.convertNumber());
       
    }
}

