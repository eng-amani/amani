float vmax=0,vmin=1023,vsample=0,vavg=0;
int i=0;
float t1,t2;
void setup() {
 Serial.begin(9600);
pinMode(13,OUTPUT);
find_max();
  find_min();
 // Serial.print(vmax);Serial.print("   ");
  //Serial.println(vmin);
  vavg=(vmax-vmin)/2+vmin;
  vmax=0;
  vmin=1023;
  //Serial.println(vavg);
t1=millis();

}

void loop() {
 vsample=analogRead(0);
 if(vsample>=(vavg))digitalWrite(13,HIGH);
 if(vsample<(vavg))digitalWrite(13,LOW);
 //Serial.println(vsample);

  

}

void find_max(void)
{
for(i=0;i<=199;i++)
{
vsample=analogRead(0);
if(vsample>=vmax)vmax=vsample;
}
}

void find_min(void)
{
  for(i=0;i<=199;i++)
{
vsample=analogRead(0);
if(vsample<=vmin)vmin=vsample;
}
}
