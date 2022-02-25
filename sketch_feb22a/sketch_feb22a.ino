void setup() {
  // put your setup code here, to run once:
const int leadPin = 13;

void setup() {
 serial.begin(9600);
 pinMode(ledPin, OUTPUT);
  
}
void loop() {
  static int delayPeriod = 100:
   static   int countDir = 1;
 
  digitalWrite(ledPin, HIGH);
  delay(delayPeriod);
  digitalWrite(ledPin, LOW);
  delay(delayPeriod);
               
 
               
 countDir = checkDirChange(delayPeriod, countDir);
               
               delayPeriod += 100 * countDir;
               serial.print("New wait Time : ");
               serial.println(delayPeriod);
               }
               int checkDirChange(int delayPeriod, int countDir){
                 if ((delayPeriod ==100) // {delayPeriod ==0)){. 
                  countDir *= -1;
                     
                     
                     
                     if((countDir <0){
                       serial.println("Going Down");
                     }else{
                       serial.println("Going Up");
                       
                     }
                        }return countDir;
                        
                       
