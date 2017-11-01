//Blinking LED Code Using Morse Code
//by Betto Cerrillos
//Input desired string to be converted to morse code
const String INPUT_STRING = "SOS sos!1234";
//NOTE: Only works with letters for this program
/*Does not work correctly with:
 * spaces at the beginning
 * multiple spaces between words
 * spaces after letters are finished
 */
/*RULES:
 * 1 UNIT OF TIME = DECIDED ON playMorseCode() in delay_time variable
 * 3 UNITS OF TIME AFTER EACH LETTER
 * 7 UNITS OF TIME AFTER EACH WORD
 * 1 UNIT OF TIME FOR A '.'
 * 3 UNITS OF TIME FOR A '-'
 * 1 UNIT OF TIME FOR A ' '
 */


String morse_string = "";

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  morse_string = makeValidInput(INPUT_STRING);//Now a string made up of spaces and capital letters
  morse_string = convertToMorse(morse_string);//Now a string made up of '.' '-' and ' ' characters for morse code
  playMorseCode(morse_string);
}

void loop() {
  //After playing the morse code, it blinks normally (every second)
  digitalWrite(13,HIGH);//LED on
  delay(1000);
  digitalWrite(13,LOW);//LED off
  delay(1000);
}

//Returns a string containing only capital letters
//If no letters, then returns an empty string
String makeValidInput(String in){
  String returned_string = "";
  for(int i = 0; i < in.length(); i++){
    if(isAlpha(in.charAt(i))|| isSpace(in.charAt(i))){
      //Adds character to the string to be returned if it is a letter or space
      returned_string+=in.charAt(i);
    }
    }
    returned_string.toUpperCase();//Convert string of letters to uppercase
  return returned_string;
}

//Plays morse code with the LED using rules as described in the convertToMorse function
//Assume that morse is a string that contains only '.' '-' and ' ' characters
void playMorseCode(String morse){
  int delay_time = 750; //Each unit of time is 750 milliseconds
  char temp_char_morse;
  digitalWrite(13, LOW);//Ensure to turn off LED
  for(int i = 0; i < morse.length();i++){
    temp_char_morse = morse.charAt(i);
    digitalWrite(13,LOW);
    if(temp_char_morse == '.'){
      digitalWrite(13,HIGH);
      delay(delay_time);
    }else if(temp_char_morse == '-'){
      digitalWrite(13,HIGH);
      delay(delay_time*3); //LED stays on for 3 units of time
    }else{
      delay(delay_time); //Does nothing if it is a space
    }
  }
}

//Returns a string with '.', '-', ' ' characters
//represents a tap, a long tap, and a wait, respectively
//a tap represents 1 unit, long tap represents 3 units, and each space represents 1 unit (of time)
//Between letters of the same word is 3 units of time, between words it is 7 units of time  
//Assume parameter string is only capital letters and spaces or an empty string
String convertToMorse(String in){
  String morse_converted = "";
  for(int i=0; i < in.length();i++){
    char temp_char = in.charAt(i);
    switch(temp_char){ //Each case has 3 units of space after according to rules
      case 'A':
      morse_converted+=". -   ";
      break;
      case 'B':
      morse_converted+="- . . .   ";
      break;
      case 'C':
      morse_converted+="- . - .   ";
      break;
      case 'D':
      morse_converted+="- . .   ";
      break;
      case 'E':
      morse_converted +=".   ";
      break;
      case 'F':
      morse_converted +=". . - .   ";
      break;
      case 'G':
      morse_converted +="- - .   ";
      break;
      case 'H':
      morse_converted +=". . . .   ";
      break;
      case 'I':
      morse_converted +=". .   ";
      break;
      case 'J':
      morse_converted +=". - - -   ";
      break;
      case 'K':
      morse_converted +="- . -   ";
      break;
      case 'L':
      morse_converted +=". - . .   ";
      break;
      case 'M':
      morse_converted +="- -   ";
      break;
      case 'N':
      morse_converted +="- .   ";
      break;
      case 'O':
      morse_converted +="- - -   ";
      break;
      case 'P':
      morse_converted +=". - - .   ";
      break;
      case 'Q':
      morse_converted +="- - . -   ";
      break;
      case 'R':
      morse_converted +=". - .   ";
      break;
      case 'S':
      morse_converted +=". . .   ";
      break;
      case 'T':
      morse_converted +="-   ";
      break;
      case 'U':
      morse_converted +=". . -   ";
      break;
      case 'V':
      morse_converted +=". . . -   ";
      break;
      case 'W':
      morse_converted +=". - -   ";
      break;
      case 'X':
      morse_converted +="- . . -   ";
      break;
      case 'Y':
      morse_converted +="- . - -   ";
      break;
      case 'Z':
      morse_converted +="- - . .   ";
      break;
      case ' ':
      morse_converted +="    "; //4 spaces
                                //Since each word ends with 3 spaces after: 4+3 = 7 spaces
    }
    }
    return morse_converted;
  }

