int BLUE_LED = D6;
int GREEN_LED = D5;
int RED_LED = D4;

int led_switch(String led)
{
    if (led == "red")
    {
        Particle.publish("DEBUG", "In");
        digitalWrite(RED_LED, HIGH);
    }
    else if (led == "green")
    {
        digitalWrite(GREEN_LED, HIGH);
    }
    else if (led == "blue")
    {
        digitalWrite(BLUE_LED, HIGH);
    }
}

void setup() {
    pinMode(BLUE_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    
    bool success = Particle.function("led", led_switch);
    
    if (success)
        Particle.publish("DEBUG", "Success");
    else
        Particle.publish("DEBUG", "Error");
}

void loop() {

}
