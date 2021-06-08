// Lcd pin ayarlarý
sbit LCD_RS at RB7_bit;
sbit LCD_EN at RB6_bit;
sbit LCD_D7 at RB5_bit;
sbit LCD_D6 at RB4_bit;
sbit LCD_D5 at RB3_bit;
sbit LCD_D4 at RB2_bit;
sbit LCD_D3 at RB1_bit;
sbit LCD_D2 at RB0_bit;
sbit LCD_D1 at RC1_bit;
sbit LCD_D0 at RC0_bit;

// Pin yönlendirmeleri
sbit LCD_RS_Direction at TRISB7_bit;
sbit LCD_EN_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB2_bit;
sbit LCD_D3_Direction at TRISB1_bit;
sbit LCD_D2_Direction at TRISB0_bit;
sbit LCD_D1_Direction at TRISC1_bit;
sbit LCD_D0_Direction at TRISC0_bit;

ADC_Init();                              //ADC modülünü baþlatma komutu

void main() {
int veri, gerilim, sicaklik;             //Deðiþken ayarlamalarý
char temp[10];
LCD_Init();                              //LCD baþlatma komutu
while (1){
      LCD_Cmd(_LCD_CLEAR);               //LCD ekranýný temiliyoruz
      veri = ADC_Read(2);                //AN2 pininden gelen deðeri veri deðiþkenine atýyoruz
      gerilim = (veri / 1023.00)*5000;   //Gelen veriyi maksimum deðer olan 1023'e bölüp çýkan sonucu 5000mV ile çarparak pine gelen voltajý hesaplýyoruz
      sicaklik = gerilim / 10;           //LM35 10mV hassasiyetle çalýþtýðý için bulduðum gerilimi hassasiyete bölerek sýcaklýk deðerini hesaplýyoruz
      IntToStr(sicaklik,temp);
      LCD_out(1,2,temp);                 //LCD'ye hesapladýðýmýz sýcaklýk deðerini yzdýrýyoruz
      Delay_ms(1000);                    //1 saniyelik bekleme koyarak ekranda yazan deðerin okunabilirliðini arttýrýyoruz(Okunamadan silinmesini önlüyoruz)
}
}