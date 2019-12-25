int led = 7;  
int swtch = 10; 
void setup() 
{
 pinMode(swtch, INPUT);
 pinMode(led, OUTPUT);
}

void loop()
{
 if(debounce(swtch)== LOW)
  {
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led, LOW);
  }
}
int debounce(int pin)
{
  int state, previous_state;
  previous_state = digitalRead(pin); 
  for(int i = 0; i < 25; i++)
  {
    delay(1);                       
    state = digitalRead(pin);       
    if( state != previous_state)
    {
      i = 0;                  
      previous_state = state;       
    }
  }
  return state;
}
